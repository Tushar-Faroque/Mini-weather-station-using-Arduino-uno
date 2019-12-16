#include "dht.h"
#include "MQ135.h"
#include "MQ2.h"

//change this with the pin that you use
int pin = 9; //for MQ-2
int lpg, co, smoke; //for MQ-2
MQ2 mq2(pin);
 
MQ135 gasSensor = MQ135(A0);
int sensorPin = 8; //for MQ-135
int sensorValue = 0; //for MQ-135 

dht DHT;
#define DHT11_PIN 7

/* Arduino Tutorial - Watel Level Sensor 40mm
   More info: */

const int read = A0; //Sensor AO pin to Arduino pin A0
int value;          //Variable to store the incomming data

void setup(){
  Serial.begin(9600);
  Serial.println("Date & Time, Humidity %, Temp *C, Air Quality, Water Level");
//  mq2.begin();
}

void loop()
{
//  Temp & Humidity
  int chk = DHT.read11(DHT11_PIN);
  float temp = DHT.temperature;
  float humidity = DHT.humidity;
//  Serial.print("Temperature = ");
//  Serial.print(temp);
//  Serial.println(" C");
//  Serial.print("Humidity = ");
//  Serial.print(humidity);
//  Serial.println("%");
  
//  MQ135
  sensorValue = analogRead(A0);
//  sensorValue = digitalRead(8); 
//  Serial.print("Air Quality=");
//  Serial.print(sensorValue); 
//  //concentration of carbon dioxide(PPM-parts per million)
//  Serial.println(" PPM");

//  MQ2
  /*read the values from the sensor, it returns
  *an array which contains 3 values.
  * 1 = LPG in ppm
  * 2 = CO in ppm
  * 3 = SMOKE in ppm
  */
//  float* values= mq2.read(true); //set it false if you don't want to print the values in the Serial
  
//  //lpg = values[0];
//  lpg = mq2.readLPG();
//  //co = values[1];
//  co = mq2.readCO();
//  //smoke = values[2];
//  smoke = mq2.readSmoke();

//  Water Sensor
  value = analogRead(read); //Read data from analog pin and store it to value variable
  
  if (value<=480){ 
//    Serial.println("Water level: 0mm - Empty!"); 
  }
  else if (value>480 && value<=530){ 
//    Serial.println("Water level: 0mm to 5mm"); 
  }
  else if (value>530 && value<=615){ 
//    Serial.println("Water level: 5mm to 10mm"); 
  }
  else if (value>615 && value<=660){ 
//    Serial.println("Water level: 10mm to 15mm"); 
  } 
  else if (value>660 && value<=680){ 
//    Serial.println("Water level: 15mm to 20mm"); 
  }
  else if (value>680 && value<=690){ 
//    Serial.println("Water level: 20mm to 25mm"); 
  }
  else if (value>690 && value<=700){ 
//    Serial.println("Water level: 25mm to 30mm"); 
  }
  else if (value>700 && value<=705){ 
//    Serial.println("Water level: 30mm to 35mm"); 
  }
  else if (value>705){ 
//    Serial.println("Water level: 35mm to 40mm"); 
  }

//  Pressure Sensor
    

//  ESP8266
  
  Serial.print(",");
  Serial.print(temp);
  Serial.print(",");
  Serial.print(humidity);
  Serial.print(",");
  Serial.print(sensorValue);
  Serial.print(",");
  Serial.println(value);
  
  delay(200000);
}
