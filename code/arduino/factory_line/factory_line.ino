#include "Smoothed.h"

// the <float> makes a filter for float numbers
// 20 is the weight (20 => 20%)
// 0 is the initial value of the filter
Smoothed<float> SmoothedSensor0;
Smoothed<float> SmoothedSensor1;
Smoothed<float> SmoothedSensor2;
Smoothed<float> SmoothedSensor3;
Smoothed<float> SmoothedSensor4;
Smoothed<float> SmoothedSensor5;
Smoothed<float> SmoothedSensor6;
Smoothed<float> SmoothedSensor7;
Smoothed<float> SmoothedSensor8;
Smoothed<float> SmoothedSensor9;

float       distance, duration;
const int   echo0=2, echo1=3, echo2=4, echo3=5, echo4=6, echo5=7, echo6=8, echo7=9, echo8=10, echo9=11;
const int   trigger0=12, trigger1=13, trigger2=14, trigger3=15, trigger4=16, trigger5=17, trigger6=18, trigger7=19, trigger8=20, trigger9=21;
int         numSensors=10, smoothingValue=10;
float       sensorsRawData[10];
  
void setup(){
    // initialize all serial communication with computer
    Serial.begin(9600);

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

    SmoothedSensor0.begin(SMOOTHED_AVERAGE, smoothingValue);
    SmoothedSensor1.begin(SMOOTHED_AVERAGE, smoothingValue);
    SmoothedSensor2.begin(SMOOTHED_AVERAGE, smoothingValue);
    SmoothedSensor3.begin(SMOOTHED_AVERAGE, smoothingValue);
    SmoothedSensor4.begin(SMOOTHED_AVERAGE, smoothingValue);
    SmoothedSensor5.begin(SMOOTHED_AVERAGE, smoothingValue);
    SmoothedSensor6.begin(SMOOTHED_AVERAGE, smoothingValue);
    SmoothedSensor7.begin(SMOOTHED_AVERAGE, smoothingValue);
    SmoothedSensor8.begin(SMOOTHED_AVERAGE, smoothingValue);
    SmoothedSensor9.begin(SMOOTHED_AVERAGE, smoothingValue);
    
    for(int i = 0; i<numSensors; i++) {sensorsRawData[i]=0;}
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
    
    SmoothedSensor0.add(sensorsRawData[0]);
    SmoothedSensor1.add(sensorsRawData[1]);
    SmoothedSensor2.add(sensorsRawData[2]);
    SmoothedSensor3.add(sensorsRawData[3]);
    SmoothedSensor4.add(sensorsRawData[4]);
    SmoothedSensor5.add(sensorsRawData[5]);
    SmoothedSensor6.add(sensorsRawData[6]);
    SmoothedSensor7.add(sensorsRawData[7]);
    SmoothedSensor8.add(sensorsRawData[8]);
    SmoothedSensor9.add(sensorsRawData[9]);

    Serial.println("A");    

    serialPrint(SmoothedSensor0.get());
    serialPrint(SmoothedSensor1.get());
    serialPrint(SmoothedSensor2.get());
    serialPrint(SmoothedSensor3.get());
    serialPrint(SmoothedSensor4.get());
    serialPrint(SmoothedSensor5.get());
    serialPrint(SmoothedSensor6.get());
    serialPrint(SmoothedSensor7.get());
    serialPrint(SmoothedSensor8.get());
    serialPrint(SmoothedSensor9.get());

    delay(20);    // Pause between the individual measurements
}

void readSensor(int echoPin, int triggerPin, int sensorNumber)
{
    digitalWrite(triggerPin,HIGH);     // Distance measurement by using the 10us long trigger signal
    delayMicroseconds(1);
    digitalWrite(triggerPin,LOW); 
    duration  = pulseIn(echoPin,HIGH);
    distance  = duration*340/2/10000;

    sensorsRawData[sensorNumber] = distance;
}

void serialPrint(int sensorData)
{
    if (sensorData < 2 || sensorData > 450){        // Checking whether measured value is within the permissible distance
        Serial.println(500);   // If not, an error message is output
    }
    else{
        // Serial.println("distance sensor " + String(sensorNumber) + ": " + String(distance) + " cm");    // The calculated distance is output to the console
        Serial.println(sensorData);
    }
}
