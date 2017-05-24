#include <stdio.h>
#include <ncurses.h>

 
#define WORLD_WIDTH 50
#define WORLD_HEIGHT 20
 
int main(int argc, char *argv[])
{
    WINDOW *border_up;
    int offsetx, offsety;
 
    initscr();
    curs_set(0);
    refresh();
    
    offsetx = (COLS - WORLD_WIDTH) / 2;
    offsety = (LINES - WORLD_HEIGHT) / 2;
 
    border_up = newwin(WORLD_HEIGHT,
                           WORLD_WIDTH,
                           offsety,
                           offsetx);
    box(border_up, 0, 0);

    wrefresh(border_up);
 
    getch();
 
    delwin(border_up);
 
    endwin();
 
    return 0;
 
}


