#include "render.h"

#include <ncurses.h>

void init_ncurses () {
    initscr ();
    raw ();
    keypad (stdscr, TRUE);
    noecho ();
}

void stop_ncurses () {
    refresh ();
    endwin ();
}

page_func_t landing_page (config_content_t*, installer_args_t*) {
    page_func_t page = (page_func_t){ .f = NULL };

    printw ("Welcome to the alpine installer! Press any key to continue\n");
    getch ();

    return page;
}
