#include <stdio.h>
#include <curses.h>
#include <term.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char str[120];
    char c;
    FILE *file_id;
    while (1) {
        printf("%s", ">");
        scanf("%s", str);
        if (!strcmp(str, "open")) {
            file_id = fopen("/dev/tty", "r+");
            SCREEN *termref = newterm(NULL, file_id, file_id);
            //cbreak();
            echo();
            keypad(stdscr, TRUE);
            getstr(str);
            delscreen(termref);
            printf("from curses window %s\n", str);
        }
        printf("%s\n", str);
    }
    return 0;
}
