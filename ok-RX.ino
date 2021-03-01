
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#define I2C_ADDR    0x27 // <<----- Add your address here.  Find it from I2C Scanner
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7
LiquidCrystal_I2C  lcd(I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);
int counter = 0;
float min = 9999; //minimum seen start value
float max = 0;  // maximum seen start value
String myString;
void setup() {
  lcd.begin (16, 2); //  LCD is 16 characters x 2 lines
  lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE);
  lcd.setBacklight(HIGH);  // Switch on the backlight
  lcd.home (); // go home
  Serial.begin (9600);
  Serial.print("gada888 ");
  delay(500);
  lcd.clear();

}  // END SETUP

void loop() {
  lcd.setBacklight(2);  // Switch on the backlight
  char TestData;
  while (Serial.available()) {
    char c = Serial.read();  //gets one byte from serial buffer
    myString += c; //makes the String readString
    delay(2);  //slow looping to allow buffer to fill with next character
  }
  if (myString.length() > 0) {
    Serial.print("myString ");
    Serial.println(myString);  //so you can see the captured String
    float N = myString.toFloat();  //convert readString into a number

    // Serial.println(n); //so you can see the integer
    lcd.setCursor(0, 0);
    lcd.print("Temp:");
    lcd.setCursor(6, 0);
    lcd.print(N);
    lcd.setCursor(10, 0);
    lcd.print(" C");
    myString = "";
  }
}  //END LOOP
 