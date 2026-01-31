#include "args.h"
#include "serializer.h"

#include <ncurses.h>
#include <stdio.h>

typedef enum _arg_validate_result {
    ARG_VALIDATE_OK        = 0,
    ARG_VALIDATE_NO_DRIVES = 1
} arg_validate_result_t;

typedef struct _page_func page_func_t;
typedef page_func_t (*page_func_ptr) (config_content_t* config, installer_args_t* args);

struct _page_func {
    page_func_ptr f;
};


page_func_t landing_page (config_content_t*, installer_args_t*) {
    page_func_t page = (page_func_t){ .f = NULL };

    printw ("Welcome to the alpine installer! Press any key to continue\n");
    getch ();

    return page;
}

arg_validate_result_t validate_arguments (installer_args_t* args) {
    if (args->drives[0][0] == '\0') {
        printf ("Please specify drives");
        return ARG_VALIDATE_NO_DRIVES;
    }

    return ARG_VALIDATE_OK;
}

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

int main (int argc, char* argv[]) {
    installer_args_t args = installer_args_parse (argc, argv);
    if (validate_arguments (&args) != ARG_VALIDATE_OK) {
        return 1;
    }

    config_content_t config = config_content_default ();

    init_ncurses ();
    page_func_t current_page = landing_page (&config, &args);

    while (current_page.f != NULL) {
        current_page = (current_page.f) (&config, &args);
    }

    stop_ncurses ();
    config_content_serialize (&config, NULL);
    return 0;
}
