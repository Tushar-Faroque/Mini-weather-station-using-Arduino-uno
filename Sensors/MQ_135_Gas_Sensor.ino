#include "MQ135.h"

MQ135 gasSensor = MQ135(A0);
int sensorPin = 8; //for MQ-135
int sensorValue = 0; //for MQ-135 

void setup(){
  Serial.begin(9600);
}

void loop(){
  
  sensorValue = analogRead(A0);
//  sensorValue = digitalRead(8); 
  Serial.print("Air Quality=");
  Serial.print(sensorValue); 
  //concentration of carbon dioxide(PPM-parts per million)
  Serial.println(" PPM");
  
  delay(1000);
}
