#include <stdio.h>
#include <ncurses.h>

int main(void) 
{
        initscr();
//      curs_set(0);
        printf("\033[od\33[2J");
        raw();
        int x, y, z;
for
        (x=0;x<=8;x++)
{
        mvaddch(x, 0, '|');
        mvaddch(x, 4, '|');
        mvaddch(x, 8, '|');
        mvaddch(x, 12, '|');

if
        (x%2 == 0)
{
for
        (y=0;y<=12;y++)
{
        mvaddch(x, y, '-');
}
}
        move(1,2);
}
        refresh();
        cbreak();
        getch();
        endwin();
        clear();
return 0;
}


void initBoard(int * boardData){

        int i;
for
        (i=0;i<=8;i++)
{
        boardData[i] = i+2;
}
        cbreak();
        noecho();
        keypad(stdscr, TRUE);
        getch();
}
