void setup()
{
  Serial.begin(9600);
  pinMode(D4,OUTPUT);
  pinMode(D3,INPUT);

}

void loop()
{
  digitalWrite(D4,LOW);
  delayMicroseconds(10);
  digitalWrite(D4,HIGH);
  delayMicroseconds(10);
  digitalWrite(D4,LOW);
  float t=pulseIn(D3,HIGH);
  float d=(t*0.0343)/2;
  Serial.println(d);

}
