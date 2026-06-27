#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(3, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);

}
void loop()
{
  digitalWrite(2,HIGH);
  delayMicroseconds(10);
  digitalWrite(2,LOW);
  long duration = pulseIn(3, HIGH);
  int distance = duration * 0.034 / 2;

        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Dist: ");
        lcd.print(distance);
        lcd.print("cm");

  if (distance < 20){
        digitalWrite(7,HIGH);
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
        lcd.setCursor(0,1);
        lcd.print("STOP");
        tone(9,1000);
        delay(500);
        noTone(9);
        delay(500);


  }
  else if (distance >= 20 && distance<100){
        digitalWrite(6,HIGH);
        digitalWrite(5,LOW);
        digitalWrite(7,LOW);
        lcd.setCursor(0,1);
        lcd.print("SLOW DOWN");
        tone(9,1000);
        delay(1000);
        noTone(9);
        delay(1000);

        
  }
  else {
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    noTone(9);
    lcd.setCursor(0,1);
    lcd.print("CLEAR");
    delay(1000);

  }
}
