// Initialize pins
const uint16_t HALLEFFECT_INPUT_PIN_1 = A0;
const uint16_t HALLEFFECT_INPUT_PIN_2 = A1;
const uint16_t HALLEFFECT_INPUT_PIN_3 = A2;
const uint16_t HALLEFFECT_INPUT_PIN_4 = A3;
const uint16_t HALLEFFECT_INPUT_PIN_5 = A4;
const uint16_t HALLEFFECT_INPUT_PIN_6 = A5;
const uint16_t HALLEFFECT_INPUT_PIN_7 = A6;
const uint16_t HALLEFFECT_INPUT_PIN_8 = A7;

void setup() {
  pinMode(HALLEFFECT_INPUT_PIN_1, INPUT);
  pinMode(HALLEFFECT_INPUT_PIN_2, INPUT);
  pinMode(HALLEFFECT_INPUT_PIN_3, INPUT);
  pinMode(HALLEFFECT_INPUT_PIN_4, INPUT);
  pinMode(HALLEFFECT_INPUT_PIN_5, INPUT);
  pinMode(HALLEFFECT_INPUT_PIN_6, INPUT);
  
  Serial.begin(9600);
}

void loop() {

  uint16_t hallEffectVal_1 = analogRead(HALLEFFECT_INPUT_PIN_1);
  uint16_t hallEffectVal_2 = analogRead(HALLEFFECT_INPUT_PIN_2);
  uint16_t hallEffectVal_3 = analogRead(HALLEFFECT_INPUT_PIN_3);
  uint16_t hallEffectVal_4 = analogRead(HALLEFFECT_INPUT_PIN_4);
  uint16_t hallEffectVal_5 = analogRead(HALLEFFECT_INPUT_PIN_5);
  uint16_t hallEffectVal_6 = analogRead(HALLEFFECT_INPUT_PIN_6);

  // Print the raw photocell value (e,g., for Serial Console and Serial Plotter)
  Serial.print("S1: ");
  Serial.print(hallEffectVal_1);
  //  Serial.print(" || S2: ");
  //  Serial.print(hallEffectVal_2);
  //  Serial.print(" || S3: ");
  //  Serial.print(hallEffectVal_3);
  //  Serial.print(" || S4: ");
  //  Serial.print(hallEffectVal_4);
  //  Serial.print(" || S5: ");
  //  Serial.print(hallEffectVal_5);
  //  Serial.print(" || S6: ");
  //  Serial.print(hallEffectVal_6);
  
  Serial.println();

  delay(20); // read at 50Hz
}
