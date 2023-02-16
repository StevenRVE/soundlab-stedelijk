float       distance, duration;
const int   echo0=2, echo1=3, echo2=4, echo3=5, echo4=6, echo5=7, echo6=8, echo7=9, echo8=10, echo9=11;
const int   trigger0=12, trigger1=13, trigger2=14, trigger3=15, trigger4=16, trigger5=17, trigger6=18, trigger7=19, trigger8=20, trigger9=21;
int         numSensors=10;
int         sensorData[10];
  
void setup(){
    // initialize all serial communication with computer
    Serial.begin(115200);

    pinMode(echo0,INPUT);
    pinMode(echo1,INPUT);
    pinMode(echo2,INPUT);
    pinMode(echo3,INPUT);
    pinMode(echo4,INPUT);
    pinMode(echo5,INPUT);
    pinMode(echo6,INPUT);
    pinMode(echo7,INPUT);
    pinMode(echo8,INPUT);
    pinMode(echo9,INPUT);
    
    pinMode(trigger0,OUTPUT);  
    pinMode(trigger1,OUTPUT);
    pinMode(trigger2,OUTPUT);
    pinMode(trigger3,OUTPUT);
    pinMode(trigger4,OUTPUT);
    pinMode(trigger5,OUTPUT);
    pinMode(trigger6,OUTPUT);
    pinMode(trigger7,OUTPUT);
    pinMode(trigger8,OUTPUT);
    pinMode(trigger9,OUTPUT);
    
    for(int i = 0; i<numSensors; i++) {sensorData[i]=0;}
}

void loop()
{
    readSensor(echo0, trigger0, 0);
    readSensor(echo1, trigger1, 1);
    readSensor(echo2, trigger2, 2);
    readSensor(echo3, trigger3, 3);
    readSensor(echo4, trigger4, 4);
    readSensor(echo5, trigger5, 5);
    readSensor(echo6, trigger6, 6);
    readSensor(echo7, trigger7, 7);
    readSensor(echo8, trigger8, 8);
    readSensor(echo9, trigger9, 9);

    serialPrint();

    Serial.println();

    delay(20);    // Pause between the individual measurements
}

void readSensor(int echoPin, int triggerPin, int sensorNumber)
{
    digitalWrite(triggerPin,HIGH);     // Distance measurement by using the 10us long trigger signal
    delayMicroseconds(1);
    digitalWrite(triggerPin,LOW); 
    duration  = pulseIn(echoPin,HIGH);
    distance  = duration*340/2/10000;

    sensorData[sensorNumber] = distance;
}

void serialPrint()
{
    for(int sensorNumber = 0; sensorNumber < numSensors; sensorNumber++)
    {
    if (sensorData[sensorNumber] < 2 || sensorData[sensorNumber] > 60){        // Checking whether measured value is within the permissible distance
          Serial.print(" ");
          Serial.print(sensorNumber);
          Serial.print(" ");
          Serial.print(500);   // If not, an error message is output
      }
      else{
          Serial.print(" ");
          Serial.print(sensorNumber);
          Serial.print(" ");
          Serial.print(sensorData[sensorNumber]);
      }      
    }
}
