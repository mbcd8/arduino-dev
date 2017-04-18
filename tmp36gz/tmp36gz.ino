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
{
if (a >= 60 ) {
 int (h+1); }
}
  else
{
if (h >= 24); {
 int (d+1); }
}
  else
{
if (d >= 31); {
  int (m+1); }
}
if (m >= 12); {
  int (y+1); }
}
//ИСПОЛЬЗОВАНИЕ ВНУТРЕННЕГО ТАЙМЕРА
//------------------------------------------
#define TIMER_CLOCK_FREQ 2000000.0 //2MHz for /8 prescale from 16MHz
 
//Установка Таймера2.
//Конфигурирует 8-битный Таймер2 ATMega168 для выработки прерывания
//с заданной частотой.
//Возвращает начальное значение таймера, которое должно быть загружено в TCNT2
//внутри вашей процедуры ISR.
//Смотри пример использования ниже.
unsigned char SetupTimer2(float timeoutFrequency){
unsigned char result; //Начальное значение таймера.
 
//Подсчет начального значения таймера
result=(int)((257.0-(TIMER_CLOCK_FREQ/timeoutFrequency))+0.5);
//257 на самом деле должно быть 256, но я получил лучшие результаты с 257.
 
//Установки Таймер2: Делитель частоты /8, режим 0
//Частота = 16MHz/8 = 2Mhz или 0.5 мкс
//Делитель /8 дает нам хороший рабочий диапазон
//так что сейчас мы просто жестко запрограммируем это.
TCCR2A = 0;
TCCR2B = 0<<CS22 | 1<<CS21 | 0<<CS20;
 
//Подключение прерывания по переполнению Timer2
TIMSK2 = 1<<TOIE2;
 
//загружает таймер для первого цикла
TCNT2=result;
 
return(result);
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
