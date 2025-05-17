#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2);
const int redPin=9;
const int greenPin=10;
const int bluePin=11;
const int trigPin=8;
const int echoPin=12;
const int buzzerPin=7;

void setup() {
  // put your setup code here, to run once:
pinMode(redPin, OUTPUT);
pinMode(greenPin, OUTPUT);
pinMode(bluePin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(trigPin, OUTPUT);
pinMode(buzzerPin, OUTPUT);
lcd.init();
lcd.backlight();
lcd.setCursor(0,0);
Serial.print("Distanta: ");
lcd.print("Distanta: ");
lcd.setCursor(0,1);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
   digitalWrite(trigPin, LOW);


float proximitate=pulseIn(echoPin, HIGH);

float distanta= proximitate * 0.034/2;

Serial.println(distanta);
lcd.setCursor(0,1);
lcd.print("                  ");
lcd.setCursor(0,1);
lcd.print(distanta); 

if(distanta<70)
{  
  digitalWrite(redPin, 255);
  digitalWrite(greenPin, 0);
  digitalWrite(bluePin, 0);
  digitalWrite(buzzerPin, HIGH);
  
}else if(distanta<150){
  digitalWrite(redPin, 255);
  digitalWrite(greenPin, 255);
  digitalWrite(bluePin, 0);
  digitalWrite(buzzerPin,LOW);
}else{
   digitalWrite(redPin, 0);
  digitalWrite(greenPin, 255);
  digitalWrite(bluePin, 0);
  digitalWrite(buzzerPin,LOW);
}
delay(200);

}
