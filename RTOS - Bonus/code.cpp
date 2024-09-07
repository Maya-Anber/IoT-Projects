#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// Define sensor and LED pins
const int IR_SENSOR_PIN = 13;
const int PM_PIN = 12;
const int IR_LED_PIN = 14;
const int PM_LED_PIN = 27;

struct sensor_task_parameters_t {
  int sensor_pin;    // Analog pin for the sensor
  int led_pin;       // Digital pin for the LED
  int threshold;     // Threshold value for the sensor
};

// Initialize task parameters for the IR sensor and LDR
static sensor_task_parameters_t ir_sensor_params = {IR_SENSOR_PIN, IR_LED_PIN, 2000};
static sensor_task_parameters_t potentiometer_params = {12, 27, 512};

void sensor_task(void *pvParameter) {
  int sensor_pin = ((sensor_task_parameters_t *)pvParameter)->sensor_pin;
  int led_pin = ((sensor_task_parameters_t *)pvParameter)->led_pin;
  int threshold = ((sensor_task_parameters_t *)pvParameter)->threshold;

  pinMode(led_pin, OUTPUT);
  pinMode(sensor_pin, INPUT);

  while (1) {
    int sensorReading = analogRead(sensor_pin);

    if (sensorReading > threshold) {
      digitalWrite(led_pin, HIGH); // Turn on LED
    } else {
      digitalWrite(led_pin, LOW); // Turn off LED
    }

    vTaskDelay(pdMS_TO_TICKS(100)); // Delay to avoid busy-waiting
  }

  vTaskDelete(NULL);
}

void setup() {
  // Create tasks for the IR sensor and Potentiometer
  xTaskCreate(
    sensor_task,              // Task function
    "ir_sensor_task",         // Task name
    2048,                     // Stack size in words
    &ir_sensor_params,        // Pointer to parameters
    5,                        // Task priority
    NULL                      // Task handle
  );

  xTaskCreate(
    sensor_task,              // Task function
    "potentiometer_task",     // Task name
    2048,                     // Stack size in words
    &potentiometer_params,    // Pointer to parameters
    5,                        // Task priority
    NULL                      // Task handle
  );
}

void loop() {
  // Empty loop, FreeRTOS tasks run independently
}
