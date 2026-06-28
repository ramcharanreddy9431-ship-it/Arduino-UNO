#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);            // defining the lcd
Servo gateServo;                               //defining the gate

void setup()
{
  Serial.begin(9600);
  lcd.init();                                  //turning on the lcd
  lcd.backlight();                             //turning the back light on so we can see the text on lcd
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(3, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  gateServo.attach(10);

}
void loop()
{
  digitalWrite(2,HIGH);
  delayMicroseconds(10);
  digitalWrite(2,LOW);
  long duration = pulseIn(3, HIGH);            //takes the pulse input from the ultrasound sensor
  int distance = duration * 0.034 / 2;         //changes pulse input to distance input

        lcd.clear();                           //clears the lcd
        lcd.setCursor(0,0);                    //sets the lcd to top left corner (0,0) --> coordinates
        lcd.print("Dist: ");
        lcd.print(distance);
        lcd.print("cm");

  if (distance < 20){
        digitalWrite(7,HIGH);                  //red bulb glows when car is nearby
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
        lcd.setCursor(0,1);                    
        lcd.print("STOP");                     //STOP will be displayed on the second line of lcd
        tone(9,1000);                          //speaker stars playing a beeping sound(quick)
        delay(500);
        noTone(9);
        delay(500);
        gateServo.write(0);                    //parking gate closes


  }
  else if (distance >= 20 && distance<100){
        digitalWrite(6,HIGH);                 //yellow bulb glows when it detects a car being parked
        digitalWrite(5,LOW);
        digitalWrite(7,LOW);
        lcd.setCursor(0,1);
        lcd.print("SLOW DOWN");                //SLOW DOWN message will be displayed on lcd
        tone(9,1000);                          //speaker starts playing beeping sound(slow)
        delay(1000);
        noTone(9);
        delay(1000);
        gateServo.write(90);                   //gate remains open

        
  }
  else {
    digitalWrite(5,HIGH);                      //green bulb glows when it detects no car
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    noTone(9);
    lcd.setCursor(0,1);
    lcd.print("CLEAR");                        //CLEAR message is displayed on lcd
    delay(1000);                               
    gateServo.write(90);                       //gate remains open

  }
}
}
