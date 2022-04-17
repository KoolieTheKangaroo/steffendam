/*
FADING A LED WITH SINE WAVE
Andrea Toscano 2016
*/
 
// Arduino LED PIN
#define LED_PIN 9
// Baudrate for Serial Communication
#define SERIAL_BAUD 115200
 
// Time period of fading in millisecs
#define PERIOD 48000
// Angular Frequency by definition
#define OMEGA 2*PI/PERIOD
// No Phase
#define PHASE 0
// Offset of the sine wave
#define OFFSET 128
// Amplitude of the sine wave
#define AMPLITUDE 127
// Max value (255)
#define MAX_VAL 255
// Min value (0)
#define MIN_VAL 0
 
// Used to generate time for the cos wave
unsigned long timer = 0;
 
void setup() {
  // Uncomment for serial monitor
  Serial.begin(SERIAL_BAUD); 
 
}
 
void loop() {
 timer = millis(); // updating time
 int ledValue = OFFSET + AMPLITUDE*(cos((OMEGA*timer)+PHASE));
 analogWrite(LED_PIN, checkValue(ledValue));
 Serial.write(ledValue);
}
 
// Useful to avoid LED values outside the bounds [0;255]
int checkValue(int val) {
  

  return constrain(val, MIN_VAL, MAX_VAL);
}
