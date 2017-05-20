#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#define WIDTH 50
#define HEIGHT 20

int startx = 0;
int starty = 0;

/*--------------------------------------------------------------------------------------*/



//-------------------------------------------------------------------------------------

char *choices[] = { 
			"Port        :",
			"Baudrate    :",
			"ASCII|HEX   :",
			"Record      :",
                        "Date*Time   :",
			"Exit        :",
		  };
//--------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------
char *options[] = {
                                      "[ ]",
                                      "[ ]",
                                      "[ ]",
                                      "[ ]",
                                      "[ ]",
                                      "[ ]",
                  };
                        
//--------------------------------------------------------------------------------------

/*--------------------------------------------------------------------------------------*/

int n_choices = sizeof(choices) / sizeof(char *);
void print_menu(WINDOW *menu_win, int highlight);

/*--------------------------------------MAIN--------------------------------------------*/

int main()
{	

/*--------------------------------------ERROR-------------------------------------------*/

if (!initscr())
     {
         fprintf(stderr, "Error initialising ncurses.\n");
         exit(1);
     }

/*--------------------------------------------------------------------------------------*/

        WINDOW *menu_win;
	int highlight = 1;
	int choice = 0;
	int c;

	initscr();
	clear();
        
        curs_set(0); // отключаем видимость курсора.
	
        noecho();
	cbreak();	/* Line buffering disabled. pass on everything */
	startx = (50 - WIDTH) / 2; // положение окна в терминале.
	starty = (20 - HEIGHT) / 2; // положение окна в терминале.
		
	menu_win = newwin(HEIGHT, WIDTH, starty, startx);
	keypad(menu_win, TRUE);
	refresh();

/*-------------------------------------------------------------------------------------*/

start_color();                           
use_default_colors();

init_pair(1,COLOR_CYAN, COLOR_GREEN);   
init_pair(2,COLOR_CYAN, COLOR_WHITE);
init_pair(3,COLOR_BLACK, COLOR_WHITE);
init_pair(4,COLOR_WHITE, COLOR_BLACK);


/*-------------------------------------------------------------------------------------*/
	print_menu(menu_win, highlight);
	while(1)
	{	c = wgetch(menu_win);
		switch(c)
		{
                 case KEY_UP:
		 if(highlight == 1)
		 highlight = n_choices;
		 else
		 --highlight;
		 break;
			case KEY_DOWN:
			if(highlight == n_choices)
			highlight = 1;
			else 
			++highlight;
			break;
			        case 10:
				choice = highlight;
				break;
                                              case KEY_ENTER;
                                              if(== )


			default:
			mvwprintw(menu_win, 13, 25, "keypad = %3d code: '%c'", c, c);
                        refresh();
			break;
		}
		print_menu(menu_win, highlight);
		if(choice != 0)	/* User did a choice come out of the infinite loop */
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
	        
        box(menu_win, 0, 0);
//---------------------------------------------------------------------------------------
        
        wattron(menu_win, COLOR_PAIR(2));                 // активируем режим слоя цветов.
        mvwprintw(menu_win, 1, 1, "RBVT-14");             // вывод строки.
        wattroff(menu_win, COLOR_PAIR(2));
          
         wattron(menu_win, COLOR_PAIR(4));                 // активируем режим слоя цветов.
         mvwprintw(menu_win, 1, 8, "$");             // вывод строки.
         wattroff(menu_win, COLOR_PAIR(4));
        
        wattron(menu_win, COLOR_PAIR(2));
        mvwprintw(menu_win, 1, 9, "TEST232");        
        wattroff(menu_win, COLOR_PAIR(2));

     mvwprintw(menu_win, 1, 16, ":"); 
       
       wmove(menu_win, 1, 16);

      mvwprintw(menu_win, 12, 1, "================================================");
              
//------------------------------------ENABLE---------------------------------------------------        

        mvwprintw(menu_win, 13, 16, "[ ]");
        mvwprintw(menu_win, 14, 16, "[ ]");
        mvwprintw(menu_win, 15, 16, "[ ]");
        mvwprintw(menu_win, 16, 16, "[ ]");
        mvwprintw(menu_win, 17, 16, "[ ]");
        mvwprintw(menu_win, 18, 16, "[ ]");

//-------------------------------------DATE&TIME----------------------------------------
        
 //------------------------------------ENABLE---------------------------------------------------        
 
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

            for(i = 0; i < n_choices; ++i)
	{	if(highlight == i + 1) /* High light the present choice */
		{	wattron(menu_win, A_REVERSE); 
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
