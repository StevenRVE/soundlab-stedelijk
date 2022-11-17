const unsigned int HALLEFFECT_INPUT_PIN_1 = A0;
const unsigned int HALLEFFECT_INPUT_PIN_2 = A1;
const unsigned int HALLEFFECT_INPUT_PIN_3 = A2;
const unsigned int HALLEFFECT_INPUT_PIN_4 = A3;
const unsigned int HALLEFFECT_INPUT_PIN_5 = A4;
const unsigned int HALLEFFECT_INPUT_PIN_6 = A5;

void printValues(unsigned int numOfSensor)
{
  
}

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

  unsigned int hallEffectVal_1 = analogRead(HALLEFFECT_INPUT_PIN_1);
  unsigned int hallEffectVal_2 = analogRead(HALLEFFECT_INPUT_PIN_2);
  unsigned int hallEffectVal_3 = analogRead(HALLEFFECT_INPUT_PIN_3);
  unsigned int hallEffectVal_4 = analogRead(HALLEFFECT_INPUT_PIN_4);
  unsigned int hallEffectVal_5 = analogRead(HALLEFFECT_INPUT_PIN_5);
  unsigned int hallEffectVal_6 = analogRead(HALLEFFECT_INPUT_PIN_6);

  // Print the raw photocell value and the converted led value (e,g., for Serial 
  // Console and Serial Plotter)
  Serial.print("S1: ");
  Serial.print(hallEffectVal_1);
  Serial.print(" || S2: ");
  Serial.print(hallEffectVal_2);
  Serial.print(" || S3: ");
  Serial.print(hallEffectVal_3);
  Serial.print(" || S4: ");
  Serial.print(hallEffectVal_4);
  Serial.print(" || S5: ");
  Serial.print(hallEffectVal_5);
  Serial.print(" || S6: ");
  Serial.print(hallEffectVal_6);
  Serial.println();

  delay(20); // read at 50Hz
}
