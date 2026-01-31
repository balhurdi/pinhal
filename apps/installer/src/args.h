#pragma once

typedef struct _installer_args {
    char** drives;
} installer_args_t;

installer_args_t installer_args_parse (int argc, char* argv[]);