#include "serializer.h"
#include <stdio.h>

int main (int argc, char const* argv[]) {
    config_content_t config = config_content_default ();
    config_content_serialize (&config, NULL);
    return 0;
}
