//16-Channel MUX (74HC4067) Interface
//=================================================
/*
TODO
- make functions to make code more readable
-- function to save highest and lowest value for mapping function
-- readSensors (for loop from loop())
- make classes if possible
- research ways to make code more modular
- add serial/OSC connection for sending data to maxmsp
*/

//=================================================
// init variables
int MUXsignal = A3; 
int value = 0;
int S[4] = {22,24,26,28};
int MUXtable[16][4]=
{
  {0,0,0,0}, {1,0,0,0}, {0,1,0,0}, {1,1,0,0},
  {0,0,1,0}, {1,0,1,0}, {0,1,1,0}, {1,1,1,0},
  {0,0,0,1}, {1,0,0,1}, {0,1,0,1}, {1,1,0,1},
  {0,0,1,1}, {1,0,1,1}, {0,1,1,1}, {1,1,1,1}
};

//=================================================
// setups
void setup()
{
  Serial.begin(38400);
  
  pinMode(MUXsignal,INPUT);
  
  for(int i=0; i<4; i++) pinMode(S[i],OUTPUT);
}

//=================================================
// loop
void loop()
{
  readSensors();
  
  Serial.println();

  delay(20);
}

//=================================================
//methods
void selection(int j)
{ 
  digitalWrite(S[0], MUXtable[j][0]);
  digitalWrite(S[1], MUXtable[j][1]);
  digitalWrite(S[2], MUXtable[j][2]);
  digitalWrite(S[3], MUXtable[j][3]);
}

void readSensors()
{
    for(int MUXchannel=0; MUXchannel<16; MUXchannel++)
  {
    selection(MUXchannel);
    
    value = analogRead(MUXsignal);
    
    printValues(MUXchannel, value);
  }
}

void printValues(int MUXchannelNumber, int value)
{
    // Serial.print(MUXchannelNumber);
    // Serial.print(": ");
    Serial.print(value);
    Serial.print(",");
}
