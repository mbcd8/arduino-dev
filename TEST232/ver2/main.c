#include <stdio.h>                        // стандартная i/o lib.
#include <ncurses.h>                      // графика ncurses.
#include <termios.h>                      // перехват терминала.



#define WIDTH 110 // ширина окна.
#define HEIGHT 30 // высота окна.

char *options[] = {

                          "Active Port :",
                          "Baudrate    :",
                          "Reading     :",
                          "Recording   :",
                          "Date *Time  :",
                          "Exit        :",
};

int n_options = sizeof(options) / sizeof(char *);


int main(int argc, char *argv[])
{
printf("\033[0d\33[2J");



WINDOW *win = newwin(0,0,0,0);


    int offsetx, offsety;

initscr();
refresh();
raw();



/*-------------------------------------------------------------------------------------*/

start_color();                           
use_default_colors();

init_pair(1,COLOR_CYAN, COLOR_GREEN);   
init_pair(2,COLOR_CYAN, COLOR_WHITE);
init_pair(3,COLOR_BLACK, COLOR_WHITE);
init_pair(4,COLOR_WHITE, COLOR_BLACK);


/*-------------------------------------------------------------------------------------*/
    offsetx = (COLS - WIDTH) / 2;
    offsety = (LINES - HEIGHT) / 2;

    win = newwin(HEIGHT,
                         WIDTH,
                         offsety,
                         offsetx);

    box(win, 0 , 0);
/*-------------------------------------------------------------------------------------*/

attron(COLOR_PAIR(1));                 // активируем режим слоя цветов.
mvprintw(10, 26, "RBVT-14");             // вывод строки.
attroff(COLOR_PAIR(1));                // выключаем режим слоя цветов.

mvaddch(10, 33,'$');                            // добавляем вывод последовательно.

// addch(':');
// move(10,42);

   
mvprintw(10, 34, "TEST232");            // выводим текст с параметрами местоположения.


attron(COLOR_PAIR(2));
  mvprintw(36, 26, "Date : %s\n", __DATE__ );  // вывод даты из системы.
attroff(COLOR_PAIR(2)); 

attron(COLOR_PAIR(2));
  mvprintw(37, 26, "Time : %s\n", __TIME__ );  // вывод времени из системы.
attroff(COLOR_PAIR(2));

attron(COLOR_PAIR(2));
  mvprintw(37, 41, ":00"); // костыль.
attroff(COLOR_PAIR(2));

mvaddch(10, 41,':');       // ввод для консоли.

 touchwin(win);
 wrefresh(win);


getch();
delwin(win);                 // ожидание user ввода.
delwin(win);
endwin();                 // завершение текущего режима curses.

return 0;
}

