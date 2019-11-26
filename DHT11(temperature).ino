#include <dht.h> //including the dht library

dht DHT;

#define DHT11_PIN 7 //setting the dht at pin 7 in arduino uno

void setup(){
  Serial.begin(9600);    //speed 9600 bits per second
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);// read datas and store it to the variables
  Serial.print("Temperature = "); //printing the values on the serial monitor
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(1000);       // the arduino waits for a second
}
