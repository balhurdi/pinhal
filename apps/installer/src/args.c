#include "args.h"
#include <argp.h>
#include <stddef.h>
#include <string.h>


static struct argp_option options[] = {
    { "drives", 'd', "SYSTEM DRIVES", 0, "List of drives available in the system" }, { 0 }
};


static char doc[] = "Installer for pinhal distro";

static int parse_drives (char* drive_list,
char drives[MAX_NUMBER_DRIVES][MAX_DRIVE_NAME_SIZE]) {
    char* token = strtok (drive_list, ",");

    if (token == NULL) {
        return 1; // TODO Return a meaningful error here
    }

    int current_index = 0;

    while (token != NULL) {

        if (current_index >= MAX_NUMBER_DRIVES || strlen (token) >= MAX_DRIVE_NAME_SIZE) {
            printf ("Drive program setup is not compliant! Submit a bug!\n");
            break;
        }

        strcpy (drives[current_index], token);
        token = strtok (NULL, ",");
        current_index++;
    }

    return 0;
}

static error_t parse_opt (int key, char* arg, struct argp_state* state) {
    installer_args_t* arguments                         = state->input;
    char drives[MAX_NUMBER_DRIVES][MAX_DRIVE_NAME_SIZE] = {
        [0 ... MAX_NUMBER_DRIVES - 1] = { 0 }
    };

    switch (key) {
    case 'd':
        parse_drives (arg, drives);
        memcpy (arguments->drives, drives, MAX_DRIVE_NAME_SIZE * MAX_NUMBER_DRIVES);
        break;

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