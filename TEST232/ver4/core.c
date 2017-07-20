#include <stdio.h>                                                    // объявления ввода/вывода.
#include <string.h>                                                   // объявления строковых функций.
#include <unistd.h>                                                   // объявления функций UNIX.
#include <fcntl.h>                                                    // объявления управления файлами.
#include <errno.h>                                                    // объявления кодов ошибок.
#include <termios.h>                                                  // объявления управления POSIX-терминалом.
#include <sys/types.h>
#include <sys/stat.h>
 
int fd;                                                              // file дескриптор для serialport.
char buf[1024];                                                       // buf зависит от размера строки принимаемых данных.
int outa=0; 
int iIn;

int delay;
 
int open_port(void);

int main(void)

{ 
port_set:

         fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY);     // адрес порта указывается manually.


if
         (fd == -1)
{
         printf("error port\n");
         perror("open_port: Unable to open /dev/ttyUSB - ");
}

else
       
{
         struct termios options;                                     // структура для установки port.
         tcgetattr(fd, &options);                                    // чтение параметров port.
        
         cfsetispeed(&options, B9600);                             // установка input baudrate.
         cfsetospeed(&options, B9600);                             // установка output baudrate.
         
         options.c_cflag &= ~PARENB;                                 // выкл проверка четности.
         options.c_cflag &= ~CSTOPB;                                 // выкл 2-х stopbit,вкл 1 stopbit.
         options.c_cflag &= ~CSIZE;                                  // выкл bit mask.
         options.c_cflag |= CS8;                                     // вкл 8bit.
         tcsetattr(fd, TCSANOW, &options);                           // сохранение параметров порта.
        
}

printf("\033[0d\033[2J");               // очищаем окно терминала перед выводом.

printf("Activated!\n");                 // выводит в окно терминала при активном подключении.
read_port:

// printf("Disconnected!\n");

iIn=read(fd,buf,8);
sleep(1);

printf("%s",buf);                       // выводим с порта.

goto read_port;                         // перемещение на read_port.
  
}
