int sensorPin = 0; 
 
void setup()
{
  Serial.begin(9600);
}
 
void loop()                     
{
  if(Serial.available())
  {
    processSyncMessage();
  }
  if*(timeStatus()==timeNotSet)
  Serial.println("Waiting for syncronization");
  else
  digitalClockDisplay();
  delay(1000);
}
  
 int input = analogRead(sensorPin);  
 float voltage = input * 5.0;
 voltage /= 1024.0; 
 
 float temperatureC = (voltage - 0.5) * 100 ;
 Serial.println(" Temperature="); Serial.print(temperatureC);
 
 else
 {
 Serial.println(" Voltage="); Serial.print(voltage); 
 delay(2000);
 }
}
