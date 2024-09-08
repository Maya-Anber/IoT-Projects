//Use analog output IR sensor to measure the proximity around you with LED and buzzer Alarm.
#define IR_SENSOR_PIN 34  // Analog pin connected to IR sensor
#define LED_PIN 26        // GPIO pin connected to LED
#define BUZZER_PIN 27     // GPIO pin connected to Buzzer
#define THRESHOLD 100     // Proximity threshold to trigger the alarm

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);     // Set LED pin as output
  pinMode(BUZZER_PIN, OUTPUT);  // Set Buzzer pin as output
  pinMode(IR_SENSOR_PIN, INPUT);  // Set IR sensor pin as input
}

void loop() {
  int sensorValue = analogRead(IR_SENSOR_PIN);  // Read the analog value from the IR sensor
  Serial.print("IR Sensor Value: ");
  Serial.println(sensorValue);

  if (sensorValue > THRESHOLD) {
    activateAlarm();   // Activate LED and Buzzer if the sensor detects proximity below threshold
  } else {
    deactivateAlarm();  // Deactivate the LED and Buzzer
  }

  delay(100);  // Small delay for sensor reading stability
}

void activateAlarm() {
  digitalWrite(LED_PIN, HIGH);   // Turn on the LED
  digitalWrite(BUZZER_PIN, HIGH);  // Turn on the buzzer
  Serial.println("Proximity detected! Alarm activated.");
}

void deactivateAlarm() {
  digitalWrite(LED_PIN, LOW);    // Turn off the LED
  digitalWrite(BUZZER_PIN, LOW);  // Turn off the buzzer
  Serial.println("No proximity detected. Alarm deactivated.");
}

