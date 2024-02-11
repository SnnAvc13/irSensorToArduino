#include <Nextion.h>
#include <SoftwareSerial.h>

SoftwareSerial nextion(2, 3); // Define RX and TX pins for Nextion screen

#define IR_SENSOR_PIN 4 // Define pin connected to IR sensor

int ir_sensor_value;
int token_count = 0; // Token counter

void setup() {
  Serial.begin(9600);
  nextion.begin(9600); // Initialize serial communication with Nextion screen
  pinMode(IR_SENSOR_PIN, INPUT); // Set pin of IR sensor as input
}

void loop() {
  // Read value from IR sensor
  ir_sensor_value = digitalRead(IR_SENSOR_PIN);

  // If IR sensor detects something, increment token count
  if (ir_sensor_value == HIGH) {
    token_count++;
    // Print token count to Nextion screen
    nextion.print("n0.val=");
    nextion.print(token_count);
    nextion.write(0xff);
    nextion.write(0xff);
    nextion.write(0xff);
    delay(100); // Add a slight delay to prevent consecutive readings
  }
}
