int resval=0; //holds the value
int restpin= A5 //sensor pin used

void setup()
{
  Serial.begin(9600);//strts the serial console
  
}

void loop()
{
  resval= analogRead(respin); //read data from analog pin and reserve it in resval variable

  if(resval<=100)
  {
    Serial.println("Water level:Empty");
  }
  else if(resval>100 && resval<=300)
  {
    Serial.println("Water level: Low")
  }

  else if(resval>300 && resval<=330)
  {
    Serial.println("Water level: Medium")
  }

  else if(resval>330)
  {
    Serial.println("Water level: High")
  }

  delay(1000)
}
