#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
#include <AFMotor.h>
#include <Servo.h>
Servo gradus;
int a;
int b; 
int c;
void setup() {
  lcd.begin(16,2);
  lcd.setCursor (0,0);
  lcd.print("  16x2 LCD");
  lcd.setCursor (0,1);
  lcd.print("  display");
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  gradus.attach(8);
  pinMode(9,OUTPUT);
   pinMode(10,OUTPUT);
    pinMode(11,OUTPUT);
     pinMode(12,OUTPUT);

}

void loop(){
  a = analogRead(A0); Serial.println(a);Serial.println("TUPROQ NAMLIGI: ");
  lcd.setCursor(0,0);lcd.print("TUPROQ NAMLIGI: ");
  lcd.setCursor(13,0);lcd.print(a);delay(500);
  lcd.setCursor(0,1);lcd.print("YORUG' Q: ");
  lcd.setCursor(13,1);lcd.print(b);delay(500);
  b = analogRead(A1); Serial.println(b);Serial.println("YORUG' Q: ");
  if(Serial.available()>0){c=Serial.read()-48; Serial.println(c);}
  if(c==3){digitalWrite(9,1);digitalWrite(10,0);} 
   if(c==4){gradus.write(0);}  
  if(c==2){gradus.write(90);}  
   if(c==1){gradus.write(180);}  
  if(c==0){digitalWrite(9,0);digitalWrite(10,0);digitalWrite(11,0);digitalWrite(12,0);digitalWrite(13,0);}
 if(c==6){digitalWrite(11,1);digitalWrite(12,0);}
 if(c==5){digitalWrite(13,1);lcd.setCursor(0,0);lcd.print("TUPROQ NAMLIGI: ");
  lcd.setCursor(13,0);lcd.print(a);delay(500);}
  
}
