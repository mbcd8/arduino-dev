#include <SoftwareSerial.h>
//Календарь.
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
//------------------------------
 byte Second;
 byte Minute;
 byte Hour;
 byte Day;
 byte Week;
 byte Month;
 byte Year;  
 //логика календаря.
//-------------------------------------------
//  переменная (A-минуты) значения от "1-60".
//  переменная (H-часы) значения от "1-24".
//  переменная (D-дни) значения от "1-31".
//  переменная (M-месяцы) значения от "1-12".
//  переменная (Y-годы) значения от "?".
//-------------------------------------------
int a, h, d, m, y;
cin >> a >> h >> d >> m >> y;

if (a >= 60 ) {
 int (h+1);
{
  else
{
if (h >= 24); {
 int (d+1);
{
  else
{
if (d >= 31); {
  int (m+1);
{
if (m >= 12); {
  int (y+1);
}
//------------------------------------------
int sensorPin = 0; //инициализация датчика.
 
void setup()
{
  Serial.begin(9600); //установка baudrate.
}
//------------------------------------------ 
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
  if (timeStatus()==timeNotSet) 
  {
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
