#define BLYNK_TEMPLATE_ID "TMPL2fncfpLtN"
#define BLYNK_TEMPLATE_NAME "esp"
#define BLYNK_AUTH_TOKEN "iT3RMf_ITB3yMAL-haL6_rsw7NIrEKz3"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// Pin definitions
#define IR_SENSOR_PIN 4 // Pin connected to IR sensor
#define LEDPIN LED_BUILTIN       // Pin connected to LED

// Blynk credentials
char auth[] = BLYNK_AUTH_TOKEN;  
char ssid[] = "network"; 
char pass[] = "12345678";  


void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(LEDPIN, OUTPUT); // Set LED pin as output
  pinMode(IR_SENSOR_PIN, INPUT); // Set IR sensor pin as input
}

// This function is called every time the value of V3 changes
BLYNK_WRITE(V3) {
  int ledState = param.asInt(); // Get the value from the Blynk app (V3)
  digitalWrite(LEDPIN, ledState); // Control LED based on Blynk command
}

void loop() {
  Blynk.run(); // Run Blynk
  
  // Read the IR sensor value
  int irValue = digitalRead(IR_SENSOR_PIN);
  
  // Send IR sensor data to Blynk app
  Blynk.virtualWrite(V4, irValue); // Send IR sensor data to virtual pin V4
  
  delay(1000); // Delay between reads
}

