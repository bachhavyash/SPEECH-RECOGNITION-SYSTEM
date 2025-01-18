#include <SoftwareSerial.h>

// Define the serial pins for communication with the voice recognition module
SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  // Start serial communication for debugging and for communication with voice module
  Serial.begin(9600);
  mySerial.begin(9600);  // Initialize serial communication with the voice recognition module

  Serial.println("Voice recognition system ready.");
}

void loop() {
  // Check if data is available from the voice recognition module
  if (mySerial.available()) {
    // Read the incoming command (this is a simplified version, so we assume the command is a single byte)
    int command = mySerial.read();
    
    Serial.print("Received command: ");
    Serial.println(command);

    // Use a switch statement or if-else to handle different voice commands
    switch (command) {
      case 1:
        // Command 1 (e.g., "Turn on LED")
        Serial.println("Voice Command: Turn on LED");
        digitalWrite(13, HIGH); // Turn on LED on pin 13
        break;
      case 2:
        // Command 2 (e.g., "Turn off LED")
        Serial.println("Voice Command: Turn off LED");
        digitalWrite(13, LOW); // Turn off LED on pin 13
        break;
      case 3:
        // Command 3 (e.g., "Blink LED")
        Serial.println("Voice Command: Blink LED");
        for (int i = 0; i < 5; i++) {
          digitalWrite(13, HIGH);
          delay(500);
          digitalWrite(13, LOW);
          delay(500);
        }
        break;
      default:
        // If the command doesn't match, print this message
        Serial.println("Unknown voice command");
        break;
    }
  }
}
