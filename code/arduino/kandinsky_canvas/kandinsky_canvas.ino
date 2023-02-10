//16-Channel MUX (74HC4067) Interface
//=================================================
/*
TODO
- make functions to make code more readable
-- function to save highest and lowest value for mapping function
*/

//=================================================
// init variables
const int numberOfSensors = 192;
const int numberOfMUX = 12;
const int numberOfChannels = 16;

int MUXsignal = A0; 
int value = 0; 
int valueIndex = 0; int mappedValue = 0;
int printDescription = true;

int S[4] = {22,24,26,28};
int inputValuesArray[numberOfSensors];
int sortedByChannelArray[numberOfSensors];
int sortedByRowArray[numberOfSensors];
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
  Serial.begin(9600);
  
  pinMode(MUXsignal,INPUT);
  
  for(int i=0; i<4; i++) pinMode(S[i],OUTPUT);
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

void readSensorsMultipleMUX()
{
  // set valueIndex to 0 
  valueIndex = 0;

  // for loop going through all the 16 MUX channels
  for(int channel=0; channel<numberOfChannels; channel++)
  {
    // update the channel for all the MUXs
    selection(channel);
    
    // read the hall effect sensordata for all the 16 MUXs going through the channels one by one
    for(int mux=0; mux<numberOfMUX; mux++)
    {
      // write the sensor value to the inputValuesArray array using the the valueIndex for the position in the array
      inputValuesArray[valueIndex++] = analogRead(MUXsignal);   
    }
  }
}

void sortByChannel(int array[])
{
  int outputArrayIndex = 0;
  
  for(int mux=0; mux < numberOfMUX; mux++)
  {
    for(int channel=0; channel < numberOfChannels; channel++)
    {
      sortedByChannelArray[outputArrayIndex++] = array[(channel * numberOfMUX) + mux];
    }
  }
}

void sortByRow(int array[])
{
    int inputCounter = 0;
    int outputCounter = 0;
    
    for(int blockRow = 0; blockRow < 3; blockRow++)
    {
        for(int blockColumn = 0; blockColumn < 4; blockColumn++)
        {
            for(int singleRow = 0; singleRow < 4; singleRow++)
            {
                for(int singleColumn = 0; singleColumn < 4; singleColumn++)
                {
                    sortedByRowArray[outputCounter++] = array[inputCounter++];
                }
                inputCounter += numberOfMUX;
            }
            inputCounter -= 60;
        }
        inputCounter += 48;
    }
}

void printValuesFromArray(int array[])
{
  // print A at beginning of list
  Serial.println("A");

  for (int arrayIndex = 0; arrayIndex < numberOfSensors; arrayIndex++)
  {
    Serial.println(array[arrayIndex]);
  }
}

//=================================================
// loop
void loop()
{
  readSensorsMultipleMUX();

  sortByChannel(inputValuesArray);

  sortByRow(sortedByChannelArray);
  
  printValuesFromArray(sortedByRowArray);

  delay(20);
}
