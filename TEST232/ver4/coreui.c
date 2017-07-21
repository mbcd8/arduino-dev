#include <stdio.h>                                                    // объявления ввода/вывода.
#include <string.h>                                                   // объявления строковых функций.
#include <unistd.h>                                                   // объявления функций UNIX.
#include <fcntl.h>                                                    // объявления управления файлами.
#include <errno.h>                                                    // объявления кодов ошибок.
#include <termios.h>                                                  // объявления управления POSIX-терминалом.
#include <sys/types.h>
#include <sys/stat.h>
#include <ncurses.h>


#define WORLD_WIDTH 115
#define WORLD_HEIGHT 50

int fd;                                                              // file дескриптор для serialport.
char buf[1024];                                                       // buf зависит от размера строки принимаемых данных.
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

    offsetx = (COLS - WORLD_WIDTH) / 2;
    offsety = (LINES - WORLD_HEIGHT) / 2;

    menu_win = newwin(WORLD_HEIGHT,
                           WORLD_WIDTH,
                           offsety,
                           offsetx);
   //  box(menu_win, 0, 0);


port_set:

    fd = open("/dev/ttyUSB1", O_RDWR | O_NOCTTY | O_NDELAY);     // 'open_port()' - открывает serial port.

//--------------------------------------------------OPTIONS-----------------------------------------------------------------------------

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

//--------------------------------------------------KEYPAD--------------------------------------------------------------------------------
/*

status=0;

key_pad:

pad = wgetch(menu_win);
switch(pad)

{
    case 0x157:
    status++;
else

break;
}    

*/
//--------------------------------------------------OUTPUT--------------------------------------------------------------------------------

int delay=0;

read_port:

box(menu_win, 0, 0);

delay=0;
posy=2;
posx=2;

mvwprintw(menu_win, 1, posx, "Connected!");

do
{

iIn=read(fd,buf,8);
sleep(1);

mvwprintw(menu_win, posy, posx, "%d", buf);

refresh();

wrefresh(menu_win);

delay++;
posy++;

}

while(delay<47);

wclear (menu_win);

goto read_port;                                                      // прыжок на функцию 'read_port'.
}

/*

//Получаем нажатие пользователя
        switch ( getch() )
        {
            case KEY_UP:
                if ( choice ) //Если возможно, переводим указатель вверх
                    choice--; 
                break;
            case KEY_DOWN:
                if ( choice != 3 ) //Если возможно, переводим указатель вниз
                    choice++;
                break;
        }
    }

    endwin();
    return 0;
}

*/
