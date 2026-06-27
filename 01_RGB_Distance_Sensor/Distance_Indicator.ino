void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(3, INPUT);
}
void loop()
{
  digitalWrite(2,HIGH);
  delayMicroseconds(10);
  digitalWrite(2,LOW);
  long duration = pulseIn(3, HIGH);
  int distance = duration * 0.034 / 2;
  if (distance < 20){
        digitalWrite(7,HIGH);
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);

  }
  else if (distance >= 20 && distance<100){
        digitalWrite(6,HIGH);
        digitalWrite(5,LOW);
        digitalWrite(7,LOW);

  }
  else {
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);

  }
}
