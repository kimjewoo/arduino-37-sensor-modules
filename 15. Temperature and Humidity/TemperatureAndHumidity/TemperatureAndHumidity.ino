int DHpin = 2; // input/output pin
byte dat[5];   

byte read_data()
{
  byte data;
  for(int i = 0; i < 8; i++)
  {
    if(digitalRead(DHpin) == LOW)
    {
      while(digitalRead(DHpin) == LOW); // wait 50us;
      delayMicroseconds(30); //The duration of the high level is judged to determine whether the data is '0' or '1';
      if(digitalRead(DHpin) == HIGH)
        data |= (1<<(7 - i)); //High in the former, low in the post;
      while(digitalRead(DHpin) == HIGH); //Data '1', waiting for the next bit of reception;
    }
  }
  return data;
}

void start_test()
{
  digitalWrite(DHpin, LOW); //Pull down the bus to send the start signal;
  delay(30); //The delay is greater than 18 ms so that DHT 11 can detect the start signal;
  digitalWrite(DHpin, HIGH);
  delayMicroseconds(40); //Wait for DHT11 to respond;
  pinMode(DHpin, INPUT);
  while(digitalRead(DHpin) == HIGH);
  delayMicroseconds(80); //The DHT11 responds by pulling the bus low for 80us;
  if(digitalRead(DHpin) == LOW);
    delayMicroseconds(80); //DHT11 pulled up after the bus 80us to start sending data;
  for(int i = 0; i < 4; i++) //Receiving temperature and humidity data, check bits are not considered;
    dat[i] = read_data();
  pinMode(DHpin, OUTPUT);
  digitalWrite(DHpin, HIGH); //After the completion of a release of data bus, waiting for the host to start the next signal
}

void setup()
{
  Serial.begin(9600);
  pinMode(DHpin, OUTPUT);
}

void loop()
{
  start_test();
  Serial.print("Current humdity = ");
  Serial.print(dat[0], DEC); //Displays the integer bits of humidity;
  Serial.print('.');
  Serial.print(dat[1], DEC); //Displays the decimal places of the humidity;
  Serial.println('%');
  Serial.print("Current temperature = ");
  Serial.print(dat[2], DEC); //Displays the integer bits of temperature;
  Serial.print('.');
  Serial.print(dat[3], DEC); //Displays the decimal places of the temperature;
  Serial.println('C');
  delay(700);
}
