// Initialize pins
const uint16_t HALLEFFECT_INPUT_PIN_1 = A0;

void setup() {
  pinMode(HALLEFFECT_INPUT_PIN_1, INPUT);
  
  Serial.begin(9600);
}

void loop() {

  uint16_t hallEffectVal_1 = analogRead(HALLEFFECT_INPUT_PIN_1);

  // Print the raw photocell value (e,g., for Serial Console and Serial Plotter)
//  Serial.print("S1: ");
  Serial.print(hallEffectVal_1);
  
  Serial.println();

  delay(20); // read at 50Hz
}
