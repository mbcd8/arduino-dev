#include <stdio.h>                                                    // объявления ввода/вывода.
#include <string.h>                                                   // объявления строковых функций.
#include <unistd.h>                                                   // объявления функций UNIX.
#include <fcntl.h>                                                    // объявления управления файлами.
#include <errno.h>                                                    // объявления кодов ошибок.
#include <termios.h>                                                  // объявления управления POSIX-терминалом.
#include <sys/types.h>
#include <sys/stat.h>
#include <ncurses.h>


#define WORLD_WIDTH 50                                                // 115.   
#define WORLD_HEIGHT 20                                               // 50.

int filed;                                                               // file дескриптор для serialport.
char buf[64];                                                        // buf зависит от размера строки принимаемых данных.
int outa=0;
int iIn;

int status, delay, posx, posy;


int open_port(void);


int main(int argc, char *argv[])
{

    WINDOW *menu_win;
    int offsetx, offsety;

    initscr();
    curs_set(0);
    refresh();

    offsetx = (COLS - WORLD_WIDTH) / 1;
    offsety = (LINES - WORLD_HEIGHT) / 1;

    menu_win = newwin(WORLD_HEIGHT,
                           WORLD_WIDTH,
                           offsety,
                           offsetx);

port_set:

    filed = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY);     // 'open_port()' - открывает serial port.

{
         struct termios options;                                     // структура для установки port.
         tcgetattr(filed, &options);                                    // чтение параметров port.

         cfsetispeed(&options, B9600);                             // установка input baudrate.
         cfsetospeed(&options, B9600);                             // установка output baudrate.

         options.c_cflag &= ~PARENB;                                 // выкл проверка четности.
         options.c_cflag &= ~CSTOPB;                                 // выкл 2-х stopbit,вкл 1 stopbit.
         options.c_cflag &= ~CSIZE;                                  // выкл bit mask.
         options.c_cflag |= CS8;                                     // вкл 8bit.
         tcsetattr(filed, TCSANOW, &options);                           // сохранение параметров порта.

}


int delay = 0;

read_port:

box(menu_win, 0, 0);

delay=0;
posy=1;
posx=2;

mvwprintw(menu_win, 18, posx, "Connected:");
mvwprintw(menu_win, 18, posx + 34, "/dev/ttyUSB0");

do

{

iIn=read(filed,buf,12);
sleep(1);

mvwprintw(menu_win, posy, posx, "%s", buf);

refresh();

wrefresh(menu_win);

delay++;
posy++;

}

while(delay < 16);

wclear (menu_win);

goto read_port;                                                      // прыжок на функцию 'read_port'.

}

/*

char* messageRcv;
messageRcv = stream_rcv_nblock(stream);

if(messageRcv != NULL) {
    if(messageRcv[0] != '\xFF') {
        printw("%s", messageRcv);
        refresh();
    }

    free(messageRcv);
}

*/
