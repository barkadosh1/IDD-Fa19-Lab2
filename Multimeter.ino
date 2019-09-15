// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print "Value is:", and set cursor to column 0, line 0
  lcd.setCursor(0, 0);
  lcd.print("Value is:");
}

void loop() {
  // set the cursor to column 0, line 1
  lcd.setCursor(0, 1);
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // Print the value detected at A0 
  lcd.print(sensorValue);
  // delay the lop by <sensorValue> milliseconds:
  delay(sensorValue);
}
