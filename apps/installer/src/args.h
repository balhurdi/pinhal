#pragma once

#define MAX_NUMBER_DRIVES 32   // TODO This might be a problem
#define MAX_DRIVE_NAME_SIZE 32 // TODO This might be a problem

typedef struct _installer_args {
    char drives[MAX_NUMBER_DRIVES][MAX_DRIVE_NAME_SIZE];
} installer_args_t;

installer_args_t installer_args_parse (int argc, char* argv[]);