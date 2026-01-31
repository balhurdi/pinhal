#include "serializer.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#define SAVE_LINE_TO_FILE(FILE, VAR_NAME, ADD_QUOTES, PARAM)           \
    ADD_QUOTES ? fprintf (FILE, #PARAM "=\"%s\"\n", VAR_NAME->PARAM) : \
                 fprintf (FILE, #PARAM "=%s\n", VAR_NAME->PARAM);

config_content_t config_content_default () {
    config_content_t content = {
        .KEYMAPOPTS     = "none",
        .HOSTNAMEOPTS   = "alpine",
        .DEVDOPTS       = "mdev",
        .INTERFACESOPTS = "auto lo\n"
                          "iface lo inet loopback\n"
                          "\n"
                          "auto eth0\n"
                          "iface eth0 inet dhcp\n"
                          "hostname alpine-test",

        .DNSOPTS      = "none",
        .TIMEZONEOPTS = "none",
        .PROXYOPTS    = "none",
        .APKREPOSOPTS = "-1 -c",
        .USEROPTS     = "-a -u -g audio,input,video,netdev juser",
        .SSHDOPTS     = "openssh",
        .NTPOPTS      = "none",
        .DISKOPTS     = "-m sys /dev/sda",
        .LBUOPTS      = "none",
        .APKCACHEOPTS = "none",
    };
    return content;
}

void config_content_serialize (const config_content_t* config, const char* path) {

    FILE* file_ptr = NULL;
    if (path == NULL) {
        file_ptr = stdout;
    } else {
        file_ptr = fopen (path, "w");
    }

    // TODO This code seems stupid and there is probably a better way to do this?
    SAVE_LINE_TO_FILE (file_ptr, config, false, KEYMAPOPTS);
    SAVE_LINE_TO_FILE (file_ptr, config, false, HOSTNAMEOPTS);
    SAVE_LINE_TO_FILE (file_ptr, config, false, DEVDOPTS);
    SAVE_LINE_TO_FILE (file_ptr, config, true, INTERFACESOPTS);
    SAVE_LINE_TO_FILE (file_ptr, config, false, DNSOPTS);
    SAVE_LINE_TO_FILE (file_ptr, config, false, TIMEZONEOPTS);
    SAVE_LINE_TO_FILE (file_ptr, config, false, PROXYOPTS);
    SAVE_LINE_TO_FILE (file_ptr, config, true, APKREPOSOPTS);
    SAVE_LINE_TO_FILE (file_ptr, config, true, USEROPTS);
    SAVE_LINE_TO_FILE (file_ptr, config, false, SSHDOPTS);
    SAVE_LINE_TO_FILE (file_ptr, config, false, NTPOPTS);
    SAVE_LINE_TO_FILE (file_ptr, config, true, DISKOPTS);
    SAVE_LINE_TO_FILE (file_ptr, config, false, LBUOPTS);
    SAVE_LINE_TO_FILE (file_ptr, config, false, APKCACHEOPTS);

    fclose (file_ptr);
}
