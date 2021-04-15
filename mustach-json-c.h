/*
 Author: José Bollo <jobol@nonadev.net>

 https://gitlab.com/jobol/mustach

 SPDX-License-Identifier: ISC
*/

#ifndef _mustach_json_c_h_included_
#define _mustach_json_c_h_included_

/*
 * mustach-json-c is intended to make integration of json-c
 * library by providing integrated functions.
 */

#include <json-c/json.h>
#include "mustach-wrap.h"

/**
 * mustach_json_c_file - Renders the mustache 'template' in 'file' for 'root'.
 *
 * @template: the template string to instanciate
 * @root:     the root json object to render
 * @file:     the file where to write the result
 *
 * Returns 0 in case of success, -1 with errno set in case of system error
 * a other negative value in case of error.
 */
extern int mustach_json_c_file(const char *template, struct json_object *root, int flags, FILE *file);

/**
 * mustach_json_c_fd - Renders the mustache 'template' in 'fd' for 'root'.
 *
 * @template: the template string to instanciate
 * @root:     the root json object to render
 * @fd:       the file descriptor number where to write the result
 *
 * Returns 0 in case of success, -1 with errno set in case of system error
 * a other negative value in case of error.
 */
extern int mustach_json_c_fd(const char *template, struct json_object *root, int flags, int fd);

/**
 * mustach_json_c_mem - Renders the mustache 'template' in 'result' for 'root'.
 *
 * @template: the template string to instanciate
 * @root:     the root json object to render
 * @result:   the pointer receiving the result when 0 is returned
 * @size:     the size of the returned result
 *
 * Returns 0 in case of success, -1 with errno set in case of system error
 * a other negative value in case of error.
 */
extern int mustach_json_c_mem(const char *template, struct json_object *root, int flags, char **result, size_t *size);

/**
 * mustach_json_c_write - Renders the mustache 'template' for 'root' to custom writer 'writecb' with 'closure'.
 *
 * @template: the template string to instanciate
 * @root:     the root json object to render
 * @writecb:  the function that write values
 * @closure:  the closure for the write function
 *
 * Returns 0 in case of success, -1 with errno set in case of system error
 * a other negative value in case of error.
 */
extern int mustach_json_c_write(const char *template, struct json_object *root, int flags, mustach_write_cb_t *writecb, void *closure);

/**
 * mustach_json_c_emit - Renders the mustache 'template' for 'root' to custom emiter 'emitcb' with 'closure'.
 *
 * @template: the template string to instanciate
 * @root:     the root json object to render
 * @emitcb:   the function that emit values
 * @closure:  the closure for the write function
 *
 * Returns 0 in case of success, -1 with errno set in case of system error
 * a other negative value in case of error.
 */
extern int mustach_json_c_emit(const char *template, struct json_object *root, int flags, mustach_emit_cb_t *emitcb, void *closure);

/* compatibility with versions before 1.0.0 */

typedef mustach_write_cb_t *mustach_json_write_cb;
extern int fmustach_json_c(const char *template, struct json_object *root, FILE *file);
extern int fdmustach_json_c(const char *template, struct json_object *root, int fd);
extern int mustach_json_c(const char *template, struct json_object *root, char **result, size_t *size);
extern int umustach_json_c(const char *template, struct json_object *root, mustach_write_cb_t *writecb, void *closure);

#endif
