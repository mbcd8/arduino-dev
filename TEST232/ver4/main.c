#include <stdio.h>                                  // стандартный I/O.
#include <stdlib.h>                                 // поддержка calloc().
#include <string.h>                                 // строковые функции.
#include <unistd.h>                                 // функции UNIX.
#include <fcntl.h>                                  // управление файлами.
#include <errno.h>                                  //  коды ошибок.
#include <termios.h>                                // управление POSIX-терминалом.
#include <sys/types.h>
#include <sys/stat.h>
#include <SDL2/SDL.h>                               // звук sdl2.
#include <ncurses.h>                                // графика ncurses.

#define WIDTH 50
#define HEIGHT 20

int startx = 0;                                     // .
int starty = 0;                                     // .
int posx = 0;                                       // позиция для choices по "x" координате..
int posy = 0;                                       // позиция для choises по "y" координате.

/*------------------------------------DEFINE---------------------------------------------*/



/*--------------------------MENU#1 LIST--------------------------------------------------*/

char *choices[] = { 
			"Port        :",
			"Baudrate    :",
			"ASCII|HEX   :",
			"Record      :",
                        "TCP/IP      :",
			"Exit        :",
};

/*--------------------------------------------------------------------------------------*/


/*-------------------------------------ON/OFF-------------------------------------------*/

char *active[] = {
                                      "[ ]"
};
                        
/*-------------------------------------------------ВЫВОД НА ЭКРАН-----------------------------------------------------------------------*/

char *output[] = {
                        " 0f00 ",
                        " 0f00 ",
                        " 0f00 ",
                        " 0f00 ",
                        " 0f00 ",
                        " 0f00 ",
                        " 0f00 ",
                        " 0f00 ",
};

/*--------------------------------------------------------------------------------------*/

int n_choices = sizeof(choices) / sizeof(char *);
void print_menu(WINDOW *menu_win, int highlight);

/*--------------------------------------MAIN--------------------------------------------*/

int main()
{	

/*--------------------------------------ERROR 1---------------------------------------*/

/* критическая ошибка.программа не запускается так как не инициализируется библиотека ncurses. */

if
         (!initscr())
{
         fprintf(stderr, "NCURSES ERROR!.\n");
         exit(1);
}

//--------------------------------------ERROR 2----------------------------------------

/* некритическая ошибка.если терминал не поддерживает цветной режим то программа инициализируется в B&W режиме. */

if
        (has_colors() == FALSE)
{
        endwin();
        printf("TERMINAL DON'T SUPPORT COLOR MODE!\n");
        exit(1);
}

/*--------------------------------------------------------------------------------------*/

        WINDOW *menu_win;
	int highlight = 1;                                // значение подстветки активированно.
	int choice = 0;                                   // для скроллинга списка.
	int pad;                                          // обьявление переменной для введенного символа.
        int time;                                         // обьявление переменной для перехвата времени.

	initscr();                                        // активируем режим ncurses.
	clear();                                          // очищение экрана ncurses.
        
        curs_set(0);                                      // отключаем видимость курсора.
	
        noecho();
	cbreak();   	                                  // пропуск.
	startx = (50 - WIDTH) / 1;                        // расположение окна в терминале по горизонтали.
	starty = (20 - HEIGHT) / 1;                       // расположение окна в терминале по вертикали.
		
	menu_win = newwin(HEIGHT, WIDTH, starty, startx);
	keypad(menu_win, TRUE);
	refresh();                                        // обновления окна.

/*----------------------------------------------------COLORS----------------------------------------------------------------------------*/

start_color();                                            // включаем цвета на ncurses.                         
use_default_colors();                                     // используем световую схему системы.

init_pair(1,COLOR_CYAN, COLOR_BLACK);                     // создаем пары цветов на ncurses.
init_pair(2,COLOR_CYAN, COLOR_WHITE);
init_pair(3,COLOR_BLACK, COLOR_WHITE);
init_pair(4,COLOR_WHITE, COLOR_BLACK);
init_pair(5,COLOR_GREEN, COLOR_GREEN);
init_pair(6,COLOR_RED, COLOR_RED);

/*-------------------------------------------------- USER KEYSTROKES------------------------------------------------------------------- */

        print_menu(menu_win, highlight);
 while(1)
{
        pad = wgetch(menu_win);
 switch(pad)
{
   case KEY_UP:                                              // функция для клавиши.
 if
                 (highlight == 1)
		 highlight = n_choices;
else
		 --highlight;
break;

   case KEY_DOWN:                                                                                      //--------------------
if
                 (highlight == n_choices)
		 highlight = 1;                              // подсветка активированна.
else 
		 ++highlight;
break;
case 10:
		 choice = highlight;
break;

/*-------------------------------------------ПЕРЕХОДЫ-----------------------------------*/

/*
  
   case KEY_RIGHT:  // клавиша (keypad = 261 code: '^E').

   highlight = 0;
   refresh();
   break;

   case KEY_LEFT:  // клавиша (keypad = 260 code: '^D').
   
   highlight = 0;
   refresh();
   break;

*/

//-----------------------------------------------------------------------------------------

                        case KEY_ENTER:
                                                                                     /*
for
                 (c = 0; c < n_choices; ++c)
{

                                                                                     */



                        highlight = 0;     // отключаем подсветку.


//                      mvwprintw(menu_win, posy, posx, "%a", active[a]);


                        refresh();         // обновление меню.
break;                                     // пауза.


//----------------------------------------TEST-------------------------------------------                                              
    /*  
   



   */
//------------------------------------------KEYCODES SNIFFER----------------------------------------
        
default:                // выполняется в любом случае.
//                        wattron(menu_win, COLOR_PAIR(2));
			mvwprintw(menu_win, 12, 21, "keypad = %3d code: '%c'", pad, pad);
//                        wattroff(menu_win, COLOR_PAIR(2));
//                      printf("\a\n");       // beep при переходе.

                        refresh();
break;
}
//----------------------------------------------------------------------------------------------
		
                print_menu(menu_win, highlight);
if
                 (choice != 0)	// выход из цикла.
break;
}	
//	mvprintw(10, 0, "You chose choice %d with choice string %s\n", choice, choices[choice - 1]);
	clrtoeol(); 
	refresh();
	endwin();
return 0;
}


void print_menu(WINDOW *menu_win, int highlight)
{
	int x, y, z, i, d, u, c;	

	x = 2;                                                // отступ списка от левой линии внутри меню.
	y = 13;                                               // отступ списка от верхней линии внутри меню.
	z = 17;
        i = 0;
        d = 5;      
        u = 1;
        c = 1;
       
        box(menu_win, 0, 0);                                   // создаем main рамку окна ncurses.

//-----------------------------------------TERMINAL--------------------------------------
  
/*
      
wattron(menu_win, COLOR_PAIR(3));                              // активируем цвет.
//     printw(20, 2, "RBVT-14");                               // вывод whoami.
       mvprintw(15, 2, "RBVT-14");
wattroff(menu_win, COLOR_PAIR(3));                             // деактивируем цвет.
          
wattron(menu_win, COLOR_PAIR(4));                              // .
        mvwprintw(menu_win, 20, 9, "$");                       // вывод строки.
wattroff(menu_win, COLOR_PAIR(4));
        
wattron(menu_win, COLOR_PAIR(3));
        mvwprintw(menu_win, 20, 10, "TEST232");                // вывод названия файла.
wattroff(menu_win, COLOR_PAIR(3));

        mvwprintw(menu_win, 20, 17, ":");                      // установка курсора.

*/       
//--------------------------------------------------------------------------------------

wattron(menu_win, COLOR_PAIR(1));
mvwprintw(menu_win, 1, 2, "|||||||");
mvwprintw(menu_win, 1, 10, "||||");
mvwprintw(menu_win, 1, 15, "||||");
mvwprintw(menu_win, 1, 20, "||||");
mvwprintw(menu_win, 1, 25, "||||");

mvwprintw(menu_win, 1, 30, "||||");
mvwprintw(menu_win, 1, 35, "||||");
mvwprintw(menu_win, 1, 40, "||||");
mvwprintw(menu_win, 1, 45, "||||");

//---------------------------------------------------------------------

mvwprintw(menu_win, 10, 2, "|||||||");
mvwprintw(menu_win, 10, 10, "||||");
mvwprintw(menu_win, 10, 15, "||||");
mvwprintw(menu_win, 10, 20, "||||");
mvwprintw(menu_win, 10, 25, "||||");
 
mvwprintw(menu_win, 10, 30, "||||");
mvwprintw(menu_win, 10, 35, "||||");
mvwprintw(menu_win, 10, 40, "||||");
mvwprintw(menu_win, 10, 45, "||||");


       
wattroff(menu_win, COLOR_PAIR(1));
//	mvwprintw(menu_win, 12, 21, "----------------------------");   


//----------------------------------------ИМИТАЦИЯ HEX OUTPUT-----------------------------------------------------------------------------
        
        wattron(menu_win, COLOR_PAIR(2));
        
        mvwprintw(menu_win, 2, 2, " 00f00 ");
        mvwprintw(menu_win, 3, 2, " 00f00 ");
        mvwprintw(menu_win, 4, 2, " 00f00 ");
        mvwprintw(menu_win, 5, 2, " 00f00 ");
       //------------------------------------
        mvwprintw(menu_win, 6, 2, " 00f00 ");
        mvwprintw(menu_win, 7, 2, " 00f00 ");
        mvwprintw(menu_win, 8, 2, " 00f00 ");
        mvwprintw(menu_win, 9, 2, " 00f00 ");        

        wattroff(menu_win, COLOR_PAIR(2));

//---------------------------------------

        wattron(menu_win, COLOR_PAIR(2));
        
        mvwprintw(menu_win, 2, 10, " 00 ");
        mvwprintw(menu_win, 3, 10, " 00 ");
        mvwprintw(menu_win, 4, 10, " 00 ");
        mvwprintw(menu_win, 5, 10, " 00 ");
        //-------------------------------
        mvwprintw(menu_win, 6, 10, " 00 ");
        mvwprintw(menu_win, 7, 10, " 00 ");
        mvwprintw(menu_win, 8, 10, " 00 ");
        mvwprintw(menu_win, 9, 10, " 00 ");
        
        wattroff(menu_win, COLOR_PAIR(2));

//---------------------------------------

        wattron(menu_win, COLOR_PAIR(2));
        
        mvwprintw(menu_win, 2, 15, " 00 ");
        mvwprintw(menu_win, 3, 15, " 00 ");
        mvwprintw(menu_win, 4, 15, " 00 ");
        mvwprintw(menu_win, 5, 15, " 00 ");
        //-------------------------------
        mvwprintw(menu_win, 6, 15, " 00 ");
        mvwprintw(menu_win, 7, 15, " 00 ");
        mvwprintw(menu_win, 8, 15, " 00 ");
        mvwprintw(menu_win, 9, 15, " 00 ");
       
        wattroff(menu_win, COLOR_PAIR(2));
//----------------------------------------
       
        wattron(menu_win, COLOR_PAIR(2));
         
        mvwprintw(menu_win, 2, 20, " 00 ");
        mvwprintw(menu_win, 3, 20, " 00 ");
        mvwprintw(menu_win, 4, 20, " 00 ");
        mvwprintw(menu_win, 5, 20, " 00 ");
        //-------------------------------
        mvwprintw(menu_win, 6, 20, " 00 ");
        mvwprintw(menu_win, 7, 20, " 00 ");
        mvwprintw(menu_win, 8, 20, " 00 ");
        mvwprintw(menu_win, 9, 20, " 00 ");
         
        wattroff(menu_win, COLOR_PAIR(2));
 
 //---------------------------------------
         
        wattron(menu_win, COLOR_PAIR(2));
         
        mvwprintw(menu_win, 2, 25, " 00 ");
        mvwprintw(menu_win, 3, 25, " 00 ");
        mvwprintw(menu_win, 4, 25, " 00 ");
        mvwprintw(menu_win, 5, 25, " 00 ");
        //-------------------------------
        mvwprintw(menu_win, 6, 25, " 00 ");
        mvwprintw(menu_win, 7, 25, " 00 ");
        mvwprintw(menu_win, 8, 25, " 00 ");
        mvwprintw(menu_win, 9, 25, " 00 ");
 
        wattroff(menu_win, COLOR_PAIR(2));
//----------------------------------------
 
        wattron(menu_win, COLOR_PAIR(2));
 
        mvwprintw(menu_win, 2, 30, " 00 ");
        mvwprintw(menu_win, 3, 30, " 00 ");
        mvwprintw(menu_win, 4, 30, " 00 ");
        mvwprintw(menu_win, 5, 30, " 00 ");
        //-------------------------------
        mvwprintw(menu_win, 6, 30, " 00 ");
        mvwprintw(menu_win, 7, 30, " 00 ");
        mvwprintw(menu_win, 8, 30, " 00 ");
        mvwprintw(menu_win, 9, 30, " 00 ");

        wattroff(menu_win, COLOR_PAIR(2));
 
  //---------------------------------------
 
        wattron(menu_win, COLOR_PAIR(2));
 
        mvwprintw(menu_win, 2, 35, " 00 ");
        mvwprintw(menu_win, 3, 35, " 00 ");
        mvwprintw(menu_win, 4, 35, " 00 ");
        mvwprintw(menu_win, 5, 35, " 00 ");
        //-------------------------------
        mvwprintw(menu_win, 6, 35, " 00 ");
        mvwprintw(menu_win, 7, 35, " 00 ");
        mvwprintw(menu_win, 8, 35, " 00 ");
        mvwprintw(menu_win, 9, 35, " 00 ");
 
        wattroff(menu_win, COLOR_PAIR(2));
//----------------------------------------

        wattron(menu_win, COLOR_PAIR(2));

        mvwprintw(menu_win, 2, 40, " 00 ");
        mvwprintw(menu_win, 3, 40, " 00 ");
        mvwprintw(menu_win, 4, 40, " 00 ");
        mvwprintw(menu_win, 5, 40, " 00 ");
        //-------------------------------
        mvwprintw(menu_win, 6, 40, " 00 ");
        mvwprintw(menu_win, 7, 40, " 00 ");
        mvwprintw(menu_win, 8, 40, " 00 ");
        mvwprintw(menu_win, 9, 40, " 00 ");

        wattroff(menu_win, COLOR_PAIR(2));

//---------------------------------------

        wattron(menu_win, COLOR_PAIR(2));

        mvwprintw(menu_win, 2, 45, " 00 ");
        mvwprintw(menu_win, 3, 45, " 00 ");
        mvwprintw(menu_win, 4, 45, " 00 ");
        mvwprintw(menu_win, 5, 45, " 00 ");
        //-------------------------------
        mvwprintw(menu_win, 6, 45, " 00 ");
        mvwprintw(menu_win, 7, 45, " 00 ");
        mvwprintw(menu_win, 8, 45, " 00 ");
        mvwprintw(menu_win, 9, 45, " 00 ");
 
        wattroff(menu_win, COLOR_PAIR(2));

//------------------------------------ENABLE---------------------------------------------        
     // wattron(menu_win, COLOR_PAIR(3));
        mvwprintw(menu_win, 13, 16, "[");
        mvwprintw(menu_win, 14, 16, "[");
        mvwprintw(menu_win, 15, 16, "[");
        mvwprintw(menu_win, 16, 16, "[");
        mvwprintw(menu_win, 17, 16, "[");
        mvwprintw(menu_win, 18, 16, "[");
     // wattroff(menu_win, COLOR_PAIR(3));
       
     // wattron(menu_win, COLOR_PAIR(3));
        mvwprintw(menu_win, 13, 18, "]");
        mvwprintw(menu_win, 14, 18, "]");
        mvwprintw(menu_win, 15, 18, "]");
        mvwprintw(menu_win, 16, 18, "]");
        mvwprintw(menu_win, 17, 18, "]");
        mvwprintw(menu_win, 18, 18, "]");
     // wattroff(menu_win, COLOR_PAIR(3));


//-------------------------------------DATE&TIME----------------------------------------
        
//-------------------------------------BORDER-------------------------------------------        
 
         mvwprintw(menu_win, 13, 20, "|");
         mvwprintw(menu_win, 14, 20, "|");
         mvwprintw(menu_win, 15, 20, "|");
         mvwprintw(menu_win, 16, 20, "|");
         mvwprintw(menu_win, 17, 20, "|");
         mvwprintw(menu_win, 18, 20, "|");
 
//-------------------------------------DATE--------------------------------------------
//------------------------------------КОСТЫЛЬ------------------------------------------ 

 wattron(menu_win, COLOR_PAIR(2));
 mvwprintw(menu_win, 13, 21, "                            ");  // костыль.
 wattroff(menu_win, COLOR_PAIR(2));


 wattron(menu_win, COLOR_PAIR(2));
 mvwprintw(menu_win, 14, 21, "                            ");  // костыль.
 wattroff(menu_win, COLOR_PAIR(2));

 wattron(menu_win, COLOR_PAIR(2));
 mvwprintw(menu_win, 15, 21, "                            ");  // костыль.
 wattroff(menu_win, COLOR_PAIR(2));

 wattron(menu_win, COLOR_PAIR(2));
 mvwprintw(menu_win, 16, 21, "                            ");  // костыль.
 wattroff(menu_win, COLOR_PAIR(2));

 wattron(menu_win, COLOR_PAIR(2));
 mvwprintw(menu_win, 17, 21, "                 ");  // костыль.
 wattroff(menu_win, COLOR_PAIR(2));
 
 wattron(menu_win, COLOR_PAIR(2));
 mvwprintw(menu_win, 18, 21, "                 ");  // костыль.
 wattroff(menu_win, COLOR_PAIR(2));

//--------------------------------------- МОДУЛЬ ДАТЫ (DD.MM.YY) -------------------------------------------------------------------------



 wattron(menu_win, COLOR_PAIR(3));
               
                mvwprintw(menu_win, 17, 38, "%s", __DATE__ );  // вывод даты из системы.

 wattroff(menu_win, COLOR_PAIR(3));
 
//-------------------------------------------МОДУЛЬ ВРЕМЯ (HH.MM.SS)----------------------------------------------------------------------

 wattron(menu_win, COLOR_PAIR(3));

                mvwprintw(menu_win, 18, 38, "%s", __TIME__ );  // вывод времени из системы.

 wattroff(menu_win, COLOR_PAIR(3));

//------------------------------------------КОСТЫЛЬ (МИЛИСЕКУНДЫ)------------------------------------------------------------------------ 

 wattron(menu_win, COLOR_PAIR(3));

                mvwprintw(menu_win, 18, 46, ":00"); // костыль.

 wattroff(menu_win, COLOR_PAIR(3));
           
//--------------------------------------------------------------MARKER--------------------------------------------------------------------

	
//----------------------------------------------------------------------------------------------------------------------------------------

for
                (i = 0; i < n_choices; ++i)
{	
if
                (highlight == i + 1)                            // подсветка на выбор в списке. 
{	


//------------------------------------------------STATUS BAR------------------------------------------------------------------------------

// алгоритм выводящий зеленый статус при активной записи,красный при выключенной и белый при режиме только мониторинга.

wattron(menu_win, COLOR_PAIR(6));
 
                mvwprintw(menu_win, d, 9, " ");
                mvwprintw(menu_win, d, 14, " ");
                mvwprintw(menu_win, d, 19, " ");
                mvwprintw(menu_win, d, 24, " ");
                mvwprintw(menu_win, d, 29, " ");
                mvwprintw(menu_win, d, 34, " ");
                mvwprintw(menu_win, d, 39, " ");
                mvwprintw(menu_win, d, 44, " ");
 
wattroff(menu_win, COLOR_PAIR(6));

//-------------------------------------------------------RECORD BAR-----------------------------------------------------------------------

// алгоритм последовательно выводящий зеленый статус при записи пакета,красный при ошибке.

                c = u + i;

wattron(menu_win, COLOR_PAIR(5));    

                mvwprintw(menu_win, c, 9, " ");
                mvwprintw(menu_win, c, 14, " ");
                mvwprintw(menu_win, c, 19, " ");
                mvwprintw(menu_win, c, 24, " ");
                mvwprintw(menu_win, c, 29, " ");
                mvwprintw(menu_win, c, 34, " ");
                mvwprintw(menu_win, c, 39, " ");
                mvwprintw(menu_win, c, 44, " ");
 
               c + 1;

wattroff(menu_win, COLOR_PAIR(5));

//----------------------------------------------------------------------------------------------------------------------------------------

                wattron(menu_win, A_REVERSE);                                 // активируем режим инверсии цвета элемента в меню.
		mvwprintw(menu_win, y, x, "%s", choices[i]);
		wattroff(menu_win, A_REVERSE);                                // деактивируем режим инверсии цвета элемента в меню.
              
//---------------------------------------------------------MARKER ATRIBUTE----------------------------------------------------------------

                mvwprintw(menu_win, y, z, "X");

//---------------------------------------------------------------------------------------------------------------------------------------

refresh();
}
else
		mvwprintw(menu_win, y, x, "%s", choices[i]);                   // перемещение курсора подстветки.
		++y;                                                           // увеличиваем переменную на один шаг.
}

//----------------------------------------------------------------------------------------------------------------------------------------
                
                                                            // MODULE.

//----------------------------------------------------------------------------------------------------------------------------------------
        
	wrefresh(menu_win);                                                     // обновление главного окна.
}

//------------------------------------------------------------CORE#----------------------------------------------------------------------------

int fd;

char buf[512];
int outa=0;
int iIn;

int open_port(void);

int core_main(void)

{
port_set:

fd = open("/dev/ttyUSB2", O_RDWR | O_NOCTTY | O_NDELAY);

if

(fd == -1)

{

printf("error port\n");
perror("open_port: Unable to open /dev/ttyUSBn - ");

}

else

{

struct termios options;
tcgetattr(fd, &options);
cfsetispeed(&options, B115200);
cfsetospeed(&options, B115200);
options.c_cflag &= ~PARENB;
options.c_cflag &= ~CSTOPB;
options.c_cflag &= ~CSIZE;
options.c_cflag |= CS8;
tcsetattr(fd, TCSANOW, &options);

}

read_port:

iIn=read(fd,buf,8);
printf("%s",buf);

goto read_port;

printf("stop\n");

}

//----------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                  // #END
//----------------------------------------------------------------------------------------------------------------------------------------------------------
