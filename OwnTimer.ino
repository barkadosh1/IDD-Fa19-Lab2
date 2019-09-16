// include the library code:
#include <LiquidCrystal.h>

// define the notes
#define REST     0
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// A variable that will be used later to adjust the time after each loop
int time_adjust = 0;

// variables/constants that will be used in reference to the button
const int  buttonPin = 0;    // the pin that the pushbutton is attached to
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonCounterComp = 0;
int buttonState = 1;         // current state of the button
int lastButtonState = 1;     // previous state of the button
int binary = 0;

// A smiley face custom character
byte smiley[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};

// A stick figure with arms down customer character
byte armsDown[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};

// A stick figure with arms up customer character
byte armsUp[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
};

// Notes for the song that will be used
int melody[] = {
  NOTE_FS5, NOTE_FS5,NOTE_D5, NOTE_B4, REST, NOTE_B4, REST, NOTE_E5, 
  REST, NOTE_E5, REST, NOTE_E5, NOTE_GS5, NOTE_GS5, NOTE_A5, NOTE_B5,
  NOTE_A5, NOTE_A5, NOTE_A5, NOTE_E5, REST, NOTE_D5, REST, NOTE_FS5,
  REST, NOTE_FS5, REST, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_E5,
  NOTE_FS5, NOTE_FS5,NOTE_D5, NOTE_B4, REST, NOTE_B4, REST, NOTE_E5, 
  
  REST, NOTE_E5, REST, NOTE_E5, NOTE_GS5, NOTE_GS5, NOTE_A5, NOTE_B5,
  NOTE_A5, NOTE_A5, NOTE_A5, NOTE_E5, REST, NOTE_D5, REST, NOTE_FS5, 
  REST, NOTE_FS5, REST, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_E5,
  NOTE_FS5, NOTE_FS5,NOTE_D5, NOTE_B4, REST, NOTE_B4, REST, NOTE_E5, 
  REST, NOTE_E5, REST, NOTE_E5, NOTE_GS5, NOTE_GS5, NOTE_A5, NOTE_B5,
  
  NOTE_A5, NOTE_A5, NOTE_A5, NOTE_E5, REST, NOTE_D5, REST, NOTE_FS5, 
  REST, NOTE_FS5, REST, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_E5, 
};

// Durations of the notes for the song that will be used
int noteDurations[] = {
  8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
  8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
};


void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print "Dance Party in:", and set cursor to column 0, line 0
  lcd.setCursor(0, 0);
  lcd.print("Dance Party in:");

  // Creating the custom characters defined above
  lcd.createChar(0, armsDown);
  lcd.createChar(1, armsUp);
  lcd.createChar(2, smiley);

  // Defining the pin that will be used with button
  pinMode(buttonPin, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  // Assigns current time 
  int time_val = millis();
  // Adjusts current time to be between 0 and 10 and subtracts it from 10
  int time_val_2 = 10 + ((-time_val + time_adjust)/1000);

  // if value is 10, print it normally
  if (time_val_2 >= 10) {
    lcd.setCursor(0, 1);
    lcd.print(time_val_2);
  }

  // if value is less than 10, print " " on one of the cursors so that the numbers print correctly 
  // since the values are now 1 digit instead of 2
  else {
    lcd.setCursor(0, 1);
    lcd.print(time_val_2);
    lcd.setCursor(1, 1);
    lcd.print(" ");
  }
  
  // Once the timer hits 0, clear the lcd display
  if (time_val_2 == 0) {
    lcd.clear();

    // Within this for loop, several things are happening
    // For one, each time through, it plays one of the notes of the song
    // Second, it draws 16 stick men and makes them move their arms up down (dancing)
    for (int thisNote = 0; thisNote < 96; thisNote++) {

    // this makes so that every third note, the stick figures have their hands up instead of down
    if (thisNote % 3 == 0) {
      binary = 1;
      }
    else {
      binary = 0;
    }

    // This sets/prints the 16 stickmen on the display
    lcd.setCursor(0, 0);
    lcd.write(byte(binary));
    lcd.setCursor(1, 1);
    lcd.write(byte(binary));
    lcd.setCursor(2, 0);
    lcd.write(byte(binary));
    lcd.setCursor(3, 1);
    lcd.write(byte(binary));
    lcd.setCursor(4, 0);
    lcd.write(byte(binary));
    lcd.setCursor(5, 1);
    lcd.write(byte(binary));
    lcd.setCursor(6, 0);
    lcd.write(byte(binary));
    lcd.setCursor(7, 1);
    lcd.write(byte(binary));
    lcd.setCursor(8, 0);
    lcd.write(byte(binary));
    lcd.setCursor(9, 1);
    lcd.write(byte(binary));
    lcd.setCursor(10, 0);
    lcd.write(byte(binary));
    lcd.setCursor(11, 1);
    lcd.write(byte(binary));
    lcd.setCursor(12, 0);
    lcd.write(byte(binary));
    lcd.setCursor(13, 1);
    lcd.write(byte(binary));
    lcd.setCursor(14, 0);
    lcd.write(byte(binary));
    lcd.setCursor(15, 1);
    lcd.write(byte(binary));
    
    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);
  
    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    
    delay(pauseBetweenNotes);
    
    // stop the tone playing:
    noTone(8);
    }

    // clear the display
    lcd.clear();

    // Print "Push The Button To Dance Again :)" on the display
    lcd.setCursor(0, 0);
    lcd.print("Push The Button");
    lcd.setCursor(0, 1);
    lcd.print("To Dance Again ");
    lcd.write(byte(2));


    // This piece of code makes it so that pushing the button will cause the overall loop() to start over
    // Initially buttonCounterComp is equal to buttonPushCounter
    while (buttonCounterComp == buttonPushCounter) {
      // Read the button state
      buttonState = digitalRead(buttonPin);

      // compare the buttonState to its previous state
      if (buttonState != lastButtonState) {      
        // if the state has changed, increment the counter  
        buttonPushCounter++;
         
        // Delay a little bit to avoid bouncing
        delay(50);
      }
    }
    // Update the second counter so that next time through, the loop won't repeat until the button is pushed
    buttonCounterComp++;

    // assigns the current time to this variable to adjust the time value at the start of the next loop
    time_adjust = millis();
  } 
}
