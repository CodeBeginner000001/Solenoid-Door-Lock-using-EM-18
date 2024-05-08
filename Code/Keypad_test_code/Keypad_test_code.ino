
#include <Keypad.h>
 
// Constants for row and column sizes
const byte ROWS = 3;
const byte COLS = 3;
 
// Array to represent keys on keypad
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'}
  
};
 
// Connections to Arduino
byte rowPins[ROWS] = {5,6,7};
byte colPins[COLS] = {8,9,10};
 
// Create keypad object
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
 
void setup() {
  // Setup serial monitor
  Serial.begin(9600);
}
 
void loop() {
  // Get key value if pressed
  char customKey = customKeypad.getKey();
 
  if (customKey) {
    // Print key value to serial monitor
    Serial.print(customKey);
  }
}
