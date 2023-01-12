float       distance, duration;
const int   echo1=A0; //selected pins
const int   trigger1=A1;
const int   echo2=A2;
const int   trigger2=A3;


void setup(){
    Serial.begin(9600);
    pinMode(echo1,INPUT);
    pinMode(trigger1,OUTPUT);
    pinMode(echo2,INPUT);
    pinMode(trigger2,OUTPUT);    
}

void loop(){

    readSensor(echo1, trigger1, 1);
    readSensor(echo2, trigger2, 2);

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
        Serial.println("distance is outside of the measuring range");   // If not, an error message is output
    }
    else{
        Serial.println("distance sensor " + String(sensorNumber) + ": " + String(distance) + " cm");    // The calculated distance is output to the console
    }
}
