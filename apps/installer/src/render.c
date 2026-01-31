#include "render.h"

#include <ncurses.h>
#include <string.h>

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

/**
 *               _       __          __
 *        ____  (_)___  / /_  ____ _/ /
 *       / __ \/ / __ \/ __ \/ __ `/ /
 *      / /_/ / / / / / / / / /_/ / /
 *     / .___/_/_/ /_/_/ /_/\__,_/_/
 *    /_/
 */

const char* LOGO_LINE1 = "               _       __          __";
const char* LOGO_LINE2 = "        ____  (_)___  / /_  ____ _/ /";
const char* LOGO_LINE3 = "       / __ \\/ / __ \\/ __ \\/ __ `/ /";
const char* LOGO_LINE4 = "      / /_/ / / / / / / / / /_/ / /  ";
const char* LOGO_LINE5 = "     / .___/_/_/ /_/_/ /_/\\__,_/_/";
const char* LOGO_LINE6 = "    /_/";


const int LOGO_WIDHT = 35;

page_func_t landing_page (config_content_t*, installer_args_t*) {
    page_func_t page = (page_func_t){ .f = NULL };

    const char* footer_message = "Press any key to continue!";

    int width = 0, height = 0;
    getmaxyx (stdscr, height, width);
    mvprintw ((int)((float)height * 0.3), (width - LOGO_WIDHT) / 2, "%s", LOGO_LINE1);
    mvprintw ((int)((float)height * 0.3) + 1, (width - LOGO_WIDHT) / 2, "%s", LOGO_LINE2);
    mvprintw ((int)((float)height * 0.3) + 2, (width - LOGO_WIDHT) / 2, "%s", LOGO_LINE3);
    mvprintw ((int)((float)height * 0.3) + 3, (width - LOGO_WIDHT) / 2, "%s", LOGO_LINE4);
    mvprintw ((int)((float)height * 0.3) + 4, (width - LOGO_WIDHT) / 2, "%s", LOGO_LINE5);
    mvprintw ((int)((float)height * 0.3) + 5, (width - LOGO_WIDHT) / 2, "%s", LOGO_LINE6);

    mvprintw ((int)((float)height * 0.7), (width - strlen (footer_message)) / 2,
    "%s", footer_message);
    getch ();

    return page;
}
