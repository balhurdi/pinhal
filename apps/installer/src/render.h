#pragma once

#include "args.h"
#include "serializer.h"

/**
 * @brief This function should be called just before ncurses based rendering
 * starts. It mutates the state of the terminal to allow for rendering.
 */
void init_ncurses ();

/**
 * @brief This function should be called just after all ncurses related calls
 * have been completed. It mutates the terminal state back to "normal" usage
 */
void stop_ncurses ();

/**
 * @page Architectural concepts behind rendering.
 *
 * How does the rendering system actually work?
 * The goal is for a series of functions with the same signature to be declared,
 * each of these functions is responsible for rendering the current page.
 *
 * All functions must return a `page_func_t` and accept both `config_content_t*`
 * and `installer_args_t*` Any function that has this signature is, itself, a
 * page_func_ptr, these properties allow for some interesting behaviour. The
 * idea here is that once my page rendering function is terminated, I always
 * return a pointer to the next page the needs to be rendered, this gives the
 * user the ability to jump from any page A to any page B without any additional
 * complexity to the code.
 *
 * When coming up with this system I was scared it might be too complicated but lets see I guess
 */
typedef struct _page_func page_func_t;
typedef page_func_t (*page_func_ptr) (config_content_t* config, installer_args_t* args);

struct _page_func {
    page_func_ptr f;
};

/**
 * @brief The first page the user sees after launching the installer
 */
page_func_t landing_page (config_content_t*, installer_args_t*);