//Use LCD module to print your name on it.
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Create an LCD object with I2C address 0x27 and 16x2 display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.begin();  // Initialize the LCD
  lcd.backlight();  // Turn on the backlight (if your LCD has one)
  lcd.setCursor(0, 0);  // Set cursor to the first column of the first row
  lcd.print("Maya Mahmoud");  // Replace with your name
}

void loop() {
  // Nothing to do here
}

