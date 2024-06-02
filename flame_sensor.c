/*
    Code by : Projects_learner
    Project name : Flame Sensor using Ardino UNO
    Modified Date : 02-06-2024
    Website : https://projectslearner.com/learn/arduino-uno-flame-sensor
*/

#define FLAME_SENSOR_PIN 2
#define EXTERNAL_LED_PIN 3

void setup() {
  pinMode(FLAME_SENSOR_PIN, INPUT);    // Initialize Flame sensor output pin as input
  pinMode(LED_BUILTIN, OUTPUT);        // Initialize built-in LED pin as output
  pinMode(EXTERNAL_LED_PIN, OUTPUT);   // Initialize external LED pin as output
  Serial.begin(9600);                  // Initialize serial communication @ 9600 baud
}

void loop() {
  // Read the state of the flame sensor
  int flameState = digitalRead(FLAME_SENSOR_PIN);

  // If fire is detected (sensor state is LOW)
  if (flameState == LOW) {
    // Turn on both LEDs
    digitalWrite(LED_BUILTIN, HIGH);    // Built-in LED ON
    digitalWrite(EXTERNAL_LED_PIN, HIGH); // External LED ON
    Serial.println("** Fire detected!!! **");
  } else {
    // Turn off both LEDs
    digitalWrite(LED_BUILTIN, LOW);     // Built-in LED OFF
    digitalWrite(EXTERNAL_LED_PIN, LOW); // External LED OFF
    Serial.println("No Fire detected");
  }
  
  delay(100);
}
