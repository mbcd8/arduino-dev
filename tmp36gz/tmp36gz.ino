#include <DateTime.h>
#include <SoftwareSerial.h>

const char* day[] =
{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
const char* month[] =
{"January", "February", "March", "April", "May", "June", "July", "August","September", "October", "November", "December"};

 byte Hour;
 byte Minute;
 byte Second;
 byte Day;
 byte DayofWeek; // Sunday is day 0 
 byte Month;     // Jan is month 0
 byte Year;      // the Year minus 1900  

int sensorPin = 0; 
 
void setup()
{
  Serial.begin(9600);
}
 
void loop()                     
{
  void serialEvent(Serial myPort)
{
 String myString = myPort.readStringUntil('\n');
 println(myString);
} 
 else
  if(Serial.available())
  {
    processSyncMessage();
  }
  if*(timeStatus()==timeNotSet)
  Serial.println("Waiting for syncronization");
  else
  digitalClockDisplay();
  delay(1000);
  
 int input = analogRead(sensorPin);  
 float voltage = input * 5.0;
 voltage /= 1024.0; 
 
 float temperatureC = (voltage - 0.5) * 100 ;
 Serial.println(" Temperature="); Serial.print(temperatureC);
 
 Serial.println(" Voltage="); Serial.print(voltage); 
 delay(2000);
 }
}
