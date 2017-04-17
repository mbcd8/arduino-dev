#include <DateTime.h>
#include <SoftwareSerial.h>

//в порядке dd.mm.yy.

//часть "dd".день.
const char* day[] =
{"Sunday",
"Monday",
"Tuesday",
"Wednesday",
"Thursday",
"Friday",
"Saturday"};

//часть "mm".месяц.
const char* month[] =
{"January",
"February",
"March",
"April",
"May",
"June",
"July",
"August",
"September",
"October",
"November",
"December"};

//часть "yy".год.ПОКА НЕТУ

 byte Hour;
 byte Minute;
 byte Second;
 byte Day;
 byte DayofWeek;
 byte Month;
 byte Year;  

int a, h, d, m, y;
cin >> a >> h >> d >> m >> y;
if (m > 2) m -= 2;
else
m += 10, y--;
int c =y / 100;

int sensorPin = 0; //инициализация датчика.
 
void setup()
{
  Serial.begin(9600); //установка baudrate.
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
  {
  if*(timeStatus()==timeNotSet) //
  Serial.println("Waiting for syncronization"); //здесь переход в ожидание.
  else
  goto //перейти в сканирование порта
  {
  if*(timeStatus()==timeNotSet) //если время получено.
  Serial.print("time"); //вывести время.
  
 //часть отвечающая за температуру.
 //работает,но требуется калибровка конвертирования.
 
 int input = analogRead(sensorPin);  
 float voltage = input * 5.0;
 voltage /= 1024.0; 
 
 float temperatureC = (voltage - 0.5) * 100 ;
 Serial.println(" Temperature=");
 Serial.print(temperatureC);
 Serial.println(" Voltage=");
 Serial.print(voltage); 
 delay(2000);
 }
}
