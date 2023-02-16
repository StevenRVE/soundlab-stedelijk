float       distance, duration;
const int   echo1=2, echo2=3, echo3=4, echo4=5, echo5=6, echo6=7, echo7=8, echo8=9, echo9=10, echo10=11;
const int   trigger1=12, trigger2=13, trigger3=14, trigger4=15, trigger5=16, trigger6=17, trigger7=18, trigger8=19, trigger9=20, trigger10=21;

// const int   numReadings = 10;

// int readings[numReadings];
// int readIndex = 0;
// int total = o;
// int average = 0;

void setup(){
    // initialize all serial communication with computer
    Serial.begin(9600);

    pinMode(echo1,INPUT);
    pinMode(echo2,INPUT);
    pinMode(echo3,INPUT);
    pinMode(echo4,INPUT);
    pinMode(echo5,INPUT);
    pinMode(echo6,INPUT);
    pinMode(echo7,INPUT);
    pinMode(echo8,INPUT);
    pinMode(echo9,INPUT);
    pinMode(echo10,INPUT);
    pinMode(trigger1,OUTPUT);
    pinMode(trigger2,OUTPUT);
    pinMode(trigger3,OUTPUT);
    pinMode(trigger4,OUTPUT);
    pinMode(trigger5,OUTPUT);
    pinMode(trigger6,OUTPUT);
    pinMode(trigger7,OUTPUT);
    pinMode(trigger8,OUTPUT);
    pinMode(trigger9,OUTPUT);
    pinMode(trigger10,OUTPUT);  
}

void loop()
{


    readSensor(echo1, trigger1, 1);
    readSensor(echo2, trigger2, 2);
    readSensor(echo3, trigger3, 3);
    readSensor(echo4, trigger4, 4);
    readSensor(echo5, trigger5, 5);
    readSensor(echo6, trigger6, 6);
    readSensor(echo7, trigger7, 7);
    readSensor(echo8, trigger8, 8);
    readSensor(echo9, trigger9, 9);
    readSensor(echo10, trigger10, 10);

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
    if (distance < 2 || distance > 450){        // Checking whether measured value is within the permissible distance
        // Serial.println("distance is outside of the measuring range");   // If not, an error message is output
        Serial.println(120);
        // Serial.print(",");
    }
    else{
        // Serial.println("distance sensor " + String(sensorNumber) + ": " + String(distance) + " cm");    // The calculated distance is output to the console
        Serial.print(distance);
        // Serial.print(",");
    }
}
