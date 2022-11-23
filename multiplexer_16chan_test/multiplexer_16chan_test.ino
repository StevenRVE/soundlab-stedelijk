//16-Channel MUX (74HC4067) Interface
//===================================
int muxSignal = A0; int value = 0; int mappedValue;
int S[4] = {5,6,7,8};
int MUXtable[16][4]=
{
  {0,0,0,0}, {1,0,0,0}, {0,1,0,0}, {1,1,0,0},
  {0,0,1,0}, {1,0,1,0}, {0,1,1,0}, {1,1,1,0},
  {0,0,0,1}, {1,0,0,1}, {0,1,0,1}, {1,1,0,1},
  {0,0,1,1}, {1,0,1,1}, {0,1,1,1}, {1,1,1,1}
};
//=================================================
void setup()
{
  Serial.begin(9600);
  
  pinMode(muxSignal,INPUT);
  
  for(int i=0; i<4; i++) pinMode(S[i],OUTPUT);
}
//=================================================
void loop()
{
  for(int i=0; i<16; i++)
  {

    selection(i);
    
    value = analogRead(muxSignal);
    mappedValue = map(value,410,500,0,100);
    
//    Serial.print(i);
//    Serial.print(": ");
    Serial.print(mappedValue);
    Serial.print("| ");
  }
  
  Serial.println();

  delay(20);

}
//=================================================
void selection(int j)
{ 
  digitalWrite(S[0], MUXtable[j][0]);
  digitalWrite(S[1], MUXtable[j][1]);
  digitalWrite(S[2], MUXtable[j][2]);
  digitalWrite(S[3], MUXtable[j][3]);
}
