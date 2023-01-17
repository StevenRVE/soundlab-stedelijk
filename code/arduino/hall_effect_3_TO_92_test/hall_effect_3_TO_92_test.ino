// Initialize pins
const uint16_t HALLEFFECT_INPUT_PIN_1 = A0;

// Define the number of samples to keep track of. The higher the number, the
// more the readings will be smoothed, but the slower the output will respond to
// the input. Using a constant rather than a normal variable lets us use this
// value to determine the size of the readings array.
const int numReadings = 10;

int readings[numReadings];  // the readings from the analog input
int readIndex = 0;          // the index of the current reading
int total = 0;              // the running total
int average = 0;            // the average

void setup() {
  pinMode(HALLEFFECT_INPUT_PIN_1, INPUT);

  for (int thisReading = 0; thisReading < numReadings; thisReading++){
    readings[thisReading] = 0;
  }
  
  Serial.begin(9600);
}

void loop() {

  uint16_t hallEffectVal_1 = analogRead(HALLEFFECT_INPUT_PIN_1);

  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = hallEffectVal_1;
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;
  // send it to the computer as ASCII digits
  Serial.print(average);
  delay(1);  // delay in between reads for stability

  // Print the raw photocell value (e,g., for Serial Console and Serial Plotter)
  // Serial.print(hallEffectVal_1);

  Serial.println();

  delay(20); // read at 50Hz
}
