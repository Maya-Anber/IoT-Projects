#include <ESP32Servo.h>  // Use ESP32Servo library instead of ESPServo

#define IR_SENSOR_PIN 34  // Analog pin connected to IR sensor
#define SERVO_PIN 5       // GPIO pin connected to the servo motor
#define THRESHOLD 100     // Threshold for detecting a person (adjust based on sensor)
#define CLOSE_DELAY 5000  // Delay in milliseconds (5 seconds) before closing the door

Servo myServo;
int sensorValue = 0;
bool doorOpen = false;
unsigned long lastDetectedTime = 0;

void setup() {
  Serial.begin(115200);
  myServo.attach(SERVO_PIN);   // Attach servo motor to pin
  myServo.write(0);            // Start with door closed (0 degrees)
  pinMode(IR_SENSOR_PIN, INPUT);
}

void loop() {
  sensorValue = analogRead(IR_SENSOR_PIN);  // Read the analog value from the IR sensor
  Serial.print("IR Sensor Value: ");
  Serial.println(sensorValue);

  if (sensorValue > THRESHOLD) {
    if (!doorOpen) {
      openDoor();   // Open the door when a person is detected
    }
    lastDetectedTime = millis();  // Update the last detection time
  } else if (doorOpen && millis() - lastDetectedTime > CLOSE_DELAY) {
    closeDoor();  // Close the door after the delay if no person is detected
  }

  delay(100);  // Small delay for sensor reading stability
}

void openDoor() {
  Serial.println("Opening door...");
  for (int angle = 0; angle <= 180; angle++) {
    myServo.write(angle);  // Rotate servo from 0 to 180 degrees
    delay(15);             // Delay to give servo time to move
  }
  doorOpen = true;         // Set door state to open
}

void closeDoor() {
  Serial.println("Closing door...");
  for (int angle = 180; angle >= 0; angle--) {
    myServo.write(angle);  // Rotate servo from 180 back to 0 degrees
    delay(15);             // Delay to give servo time to move
  }
  doorOpen = false;        // Set door state to closed
}
