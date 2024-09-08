#define IR_SENSOR_PIN 34  // Analog pin connected to IR sensor
#define RED_PIN 25        // GPIO pin connected to Red LED
#define GREEN_PIN 26      // GPIO pin connected to Green LED
#define BLUE_PIN 27       // GPIO pin connected to Blue LED
#define BUZZER_PIN 32     // GPIO pin connected to Buzzer
#define THRESHOLD 1000     // Proximity threshold to trigger the alarm

void setup() {
  Serial.begin(115200);
  pinMode(RED_PIN, OUTPUT);    // Set RGB LED pins as outputs
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT); // Set Buzzer pin as output
  pinMode(IR_SENSOR_PIN, INPUT); // Set IR sensor pin as input
}

void loop() {
  int sensorValue = analogRead(IR_SENSOR_PIN);  // Read the analog value from the IR sensor
  Serial.print("IR Sensor Value: ");
  Serial.println(sensorValue);

  if (sensorValue > THRESHOLD) {
    activateAlarm();   // Activate RGB LED and Buzzer if the sensor detects proximity below threshold
  } else {
    deactivateAlarm();  // Deactivate the RGB LED and Buzzer
  }

  delay(100);  // Small delay for sensor reading stability
}

void activateAlarm() {
  setColor(255, 0, 0);   // Set RGB LED to Red
  digitalWrite(BUZZER_PIN, HIGH);  // Turn on the buzzer
  Serial.println("Proximity detected! Alarm activated.");
}

void deactivateAlarm() {
  setColor(0, 255, 0);   // Set RGB LED to Green
  digitalWrite(BUZZER_PIN, LOW);   // Turn off the buzzer
  Serial.println("No proximity detected. Alarm deactivated.");
}

void setColor(int red, int green, int blue) {
  analogWrite(RED_PIN, red);   // Set Red LED intensity
  analogWrite(GREEN_PIN, green); // Set Green LED intensity
  analogWrite(BLUE_PIN, blue);  // Set Blue LED intensity
}
