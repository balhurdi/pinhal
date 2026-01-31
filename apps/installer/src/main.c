#include "args.h"
#include "serializer.h"

#include <stdio.h>

typedef enum _arg_validate_result {
    ARG_VALIDATE_OK        = 0,
    ARG_VALIDATE_NO_DRIVES = 1
} arg_validate_result_t;

arg_validate_result_t validate_arguments (installer_args_t* args) {
    if (args->drives[0][0] == '\0') {
        printf ("Please specify drives");
        return ARG_VALIDATE_NO_DRIVES;
    }

    return ARG_VALIDATE_OK;
}

int main (int argc, char* argv[]) {
    installer_args_t args = installer_args_parse (argc, argv);
    if (validate_arguments (&args) != ARG_VALIDATE_OK) {
        return 1;
    }

    config_content_t config = config_content_default ();
    config_content_serialize (&config, NULL);
    return 0;
}
