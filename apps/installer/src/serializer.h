#pragma once

/**
 * @note Refer to https://wiki.alpinelinux.org/wiki/Using_an_answerfile_with_setup-alpine to
 * get the list of all parameters as well as what they mean and values each field can have
 */
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

/**
 * @brief Creates a default config based on the config generated
 * by the `setup-alpine -c PATH_TO_FILENAME` command
 *
 * @note Refer to https://wiki.alpinelinux.org/wiki/Using_an_answerfile_with_setup-alpine
 */
config_content_t config_content_default ();

/**
 * @brief Generates a config file compatible with the
 * setup-alpine -f FILE_NAME command
 *
 * @param config A reference to a filled out config struct
 * @param path Path to the file, in case its NULL, it outputs to stdout
 *
 * @note Using stdout mode is a good tool for testing
 */
void config_content_serialize (const config_content_t* config, const char* path);