#pragma once

typedef struct _config_content {
    char* KEYMAPOPTS;
    char* HOSTNAMEOPTS;
    char* DEVDOPTS;
    char* INTERFACESOPTS;
    char* DNSOPTS;
    char* TIMEZONEOPTS;
    char* PROXYOPTS;
    char* APKREPOSOPTS;
    char* USEROPTS;
    char* SSHDOPTS;
    char* NTPOPTS;
    char* DISKOPTS;
    char* LBUOPTS;
    char* APKCACHEOPTS;
} config_content_t;

config_content_t config_content_default ();
void config_content_serialize (const config_content_t* config, const char* path);