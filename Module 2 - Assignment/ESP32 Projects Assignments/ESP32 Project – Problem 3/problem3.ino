#include <LiquidCrystal.h>

// Pin connections for the LCD
LiquidCrystal lcd(21, 22, 13, 12, 14, 27);

#define IR_SENSOR_PIN 34       // Analog pin connected to IR sensor output
#define THRESHOLD 50           // Threshold for detecting disconnection

void setup() {
  Serial.begin(115200);
  
  // Initialize the LCD
  lcd.begin(16, 2);  // Set the LCD's number of columns and rows
  lcd.setCursor(0, 0);
  lcd.print("IR Sensor Readings");
}

void loop() {
  int sensorValue = analogRead(IR_SENSOR_PIN);  // Read the analog value from IR sensor
  
  // Simple distance estimation (not exact, depends on your sensor)
  float distance = map(sensorValue, 0, 4095,  1, 25);  // Maps sensor value to 1mm to 25mm range
  
  // Clear and display readings on the LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  
  if (sensorValue < THRESHOLD) {  // Check if sensor value is below threshold
    lcd.print("No input detected");
    lcd.setCursor(0, 1);
    lcd.print("Connect sensor");
  } else {
    lcd.print("Distance: ");
    lcd.print(distance, 1);
    lcd.print(" mm");
  }

  delay(1000);  // Update every second
}
