#include "args.h"
#include <argp.h>
#include <stddef.h>

static struct argp_option options[] = {
    { "drives", 'd', "SYSTEM DRIVES", 0, "List of drives available in the system" }, { 0 }
};


static char doc[] = "Installer for pinhal distro";

static error_t parse_opt (int key, char* arg, struct argp_state* state) {
    installer_args_t* arguments = state->input;

    switch (key) {
    case 'd': (void)arguments->drives; break;

    default: break;
    }

    return 0;
}

static struct argp argp = { options, parse_opt, NULL, doc };


installer_args_t installer_args_parse (int argc, char* argv[]) {
    installer_args_t args = { 0 };
    argp_parse (&argp, argc, argv, 0, 0, &args);
    return args;
}