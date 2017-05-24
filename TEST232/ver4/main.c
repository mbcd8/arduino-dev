#include <stdio.h>   // стандартный I/O.
#include <stdlib.h>  // поддержка calloc().
#include <string.h>  // .
#include <ncurses.h> // поддержка ncurses.

#define WIDTH 50
#define HEIGHT 20

int startx = 0; // .
int starty = 0; // .

/*------------------------------------DEFINE---------------------------------------------*/



/*--------------------------MENU#1 LIST--------------------------------------------------*/

char *choices[] = { 
			"Port        :",
			"Baudrate    :",
			"ASCII|HEX   :",
			"Record      :",
                        "Date*Time   :",
			"Exit        :",
};

/*--------------------------------------------------------------------------------------*/


/*-------------------------------------ON/OFF-------------------------------------------*/

char *active[] = {
                                      "[ ]",
                                      "[ ]",
                                      "[ ]",
                                      "[ ]",
                                      "[ ]",
                                      "[ ]",
};
                        
/*--------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------*/

int n_choices = sizeof(choices) / sizeof(char *);
void print_menu(WINDOW *menu_win, int highlight);

/*--------------------------------------MAIN--------------------------------------------*/

int main()
{	

/*--------------------------------------TUI ERROR---------------------------------------*/

if (!initscr())
     {
         fprintf(stderr, "Error ncurses.\n");
         exit(1);
     }

/*--------------------------------------------------------------------------------------*/

        WINDOW *menu_win;
	int highlight = 1;    // значение подстветки активированно.
	int choice = 0;       // для скроллинга списка.
	int pad;              // обьявление переменной для введенного символа.
        int time;             // обьявление переменной для перехвата времени.

	initscr();            // активируем режим ncurses.
	clear();              // очищение экрана ncurses.
        
        curs_set(0);          // отключаем видимость курсора.
	
        noecho();
	cbreak();   	      // пропуск.
	startx = (50 - WIDTH) / 2; // положение окна в терминале.
	starty = (20 - HEIGHT) / 2; // положение окна в терминале.
		
	menu_win = newwin(HEIGHT, WIDTH, starty, startx);
	keypad(menu_win, TRUE);
	refresh();            // обновления окна.

/*--------------------------------------COLORS-----------------------------------------*/

start_color();                           
use_default_colors();

init_pair(1,COLOR_CYAN, COLOR_GREEN);   
init_pair(2,COLOR_CYAN, COLOR_WHITE);
init_pair(3,COLOR_BLACK, COLOR_WHITE);
init_pair(4,COLOR_WHITE, COLOR_BLACK);


/*----------------------------------------- USER KEYSTROKES--------------------------- */

        print_menu(menu_win, highlight);
 while(1)
{
        pad = wgetch(menu_win);
 switch(pad)
{
   case KEY_UP:                         // функция для клавиши.
 if
                 (highlight == 1)
		 highlight = n_choices;
else
		 --highlight;
break;

   case KEY_DOWN:
if
                 (highlight == n_choices)
		 highlight = 1;        // подсветка активированна.
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

//--------------------------------------------------------------------------------------

                        case KEY_ENTER:
                        highlight = 0;     // отключаем подсветку.

                        refresh();         // обновление меню.
break;                                     // пауза.


//----------------------------------------TEST-------------------------------------------                                              
    /*  
   



   */
//------------------------------------------KEYCODES SNIFFER----------------------------------------
        
default:                // выполняется в любом случае.
			mvwprintw(menu_win, 1, 17, "keypad = %3d code: '%c'", pad, pad);
                        refresh();
break;
}
        //----------------------------------------------------------------------------------------------
		
                print_menu(menu_win, highlight);
if
                 (choice != 0)	// выход из цикла.
break;
}	
	mvprintw(32, 0, "You chose choice %d with choice string %s\n", choice, choices[choice - 1]);
	clrtoeol(); 
	refresh();
	endwin();
return 0;
}


void print_menu(WINDOW *menu_win, int highlight)
{
	int x, y, i;	

	x = 2; // отступ списка от левой линии внутри меню.
	y = 13; // отступ спискаот верхней линии внутри меню.
	        
        box(menu_win, 0, 0);    // создаем рамку ncurses.

//-----------------------------------------TERMINAL--------------------------------------
        
        wattron(menu_win, COLOR_PAIR(2));                 // активируем цвет.
        mvwprintw(menu_win, 1, 1, "RBVT-14");             // вывод whoami.
        wattroff(menu_win, COLOR_PAIR(2));                // деактивируем цвет.
          
        wattron(menu_win, COLOR_PAIR(4));                 // .
        mvwprintw(menu_win, 1, 8, "$");             // вывод строки.
        wattroff(menu_win, COLOR_PAIR(4));
        
        wattron(menu_win, COLOR_PAIR(2));
        mvwprintw(menu_win, 1, 9, "TEST232");        // вывод названия файла.
        wattroff(menu_win, COLOR_PAIR(2));

        mvwprintw(menu_win, 1, 16, ":");               // установка курсора.

        mvwprintw(menu_win, 2, 1, "================================================");      
 
      // wmove(menu_win, 1, 16); // попытка перемещения курсора.

        mvwprintw(menu_win, 12, 1, "================================================");
              
//------------------------------------ENABLE---------------------------------------------        
     // wattron(menu_win, COLOR_PAIR(3));
        mvwprintw(menu_win, 13, 16, "[ ]");
        mvwprintw(menu_win, 14, 16, "[ ]");
        mvwprintw(menu_win, 15, 16, "[ ]");
        mvwprintw(menu_win, 16, 16, "[ ]");
        mvwprintw(menu_win, 17, 16, "[ ]");
        mvwprintw(menu_win, 18, 16, "[ ]");
     // wattroff(menu_win, COLOR_PAIR(3));

//-------------------------------------DATE&TIME----------------------------------------
        
//-------------------------------------BORDER-------------------------------------------        
 
         mvwprintw(menu_win, 13, 20, "|");
         mvwprintw(menu_win, 14, 20, "|");
         mvwprintw(menu_win, 15, 20, "|");
         mvwprintw(menu_win, 16, 20, "|");
         mvwprintw(menu_win, 17, 20, "|");
         mvwprintw(menu_win, 18, 20, "|");
 
//-------------------------------------DATE&TIME----------------------------------------

 wattron(menu_win, COLOR_PAIR(2));
 mvwprintw(menu_win, 17, 31, "Date : %s\n", __DATE__ );  // вывод даты из системы.
 wattroff(menu_win, COLOR_PAIR(2));
 
 wattron(menu_win, COLOR_PAIR(2));
 mvwprintw(menu_win, 18, 31, "Time : %s\n", __TIME__ );  // вывод времени из системы.
 wattroff(menu_win, COLOR_PAIR(2));
  
 wattron(menu_win, COLOR_PAIR(2));
 mvwprintw(menu_win, 18, 46, ":00"); // костыль.
 wattroff(menu_win, COLOR_PAIR(2));
           
//------------------------------------MARKER--------------------------------------------

	
//--------------------------------------------------------------------------------------

for
                (i = 0; i < n_choices; ++i)
{	
if
                (highlight == i + 1) /* High light the present choice */
{	
                wattron(menu_win, A_REVERSE); 
		mvwprintw(menu_win, y, x, "%s", choices[i]);
		wattroff(menu_win, A_REVERSE);
}
else
		mvwprintw(menu_win, y, x, "%s", choices[i]);
		++y;
}

//--------------------------------------------------------------------------
                
//---------------------------------------------------------------------------
        
	wrefresh(menu_win);
}
