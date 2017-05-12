#include <stdio.h>
#include <ncurses.h>

 
#define WORLD_WIDTH 50
#define WORLD_HEIGHT 20
 
int main(int argc, char *argv[])
{
    WINDOW *border_up;
    int offsetx, offsety;
 
    initscr();
    refresh();
    start_color();
    init_pair(1,COLOR_CYAN, COLOR_WHITE);

    offsetx = (COLS - WORLD_WIDTH) / 2;
    offsety = (LINES - WORLD_HEIGHT) / 2;
 
    border_up = newwin(WORLD_HEIGHT,
                           WORLD_WIDTH,
                           offsety,
                           offsetx);
 attron(COLOR_PAIR(2));
 box(border_up, 0, 0);
 attroff(COLOR_PAIR(2));
    wrefresh(border_up);
 
    getch();
 
    delwin(border_up);
 
    endwin();
 
    return 0;
 
}

