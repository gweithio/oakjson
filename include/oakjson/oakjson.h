#ifndef OAKJSON_HEADER
#define OAKJSON_HEADER

#include <stdint.h>
#include <json-c/json.h>

typedef struct {
  const char*  filepath;
  uint32_t     file_size;
  json_object* object;

} oakjson_file;

typedef struct {
  oakjson_file* file;
} oakjson_ctx;

typedef enum {
  ARRAY,
  STRING,
  OBJECT,
} oakjson_object_types;

/* creates our oakjson context by allocated the context and the file
 * returns: a pointer to the context
 */
oakjson_ctx* oakjson_ctx_create();

/* Sets the filepath for our context and constructs a JSON object
 * oak - the the context to set
 * filepath - the filepath we wish to set
 * returns: success (1) or failure (2) */
uint8_t oakjson_create_object(oakjson_ctx* oak, const char* filepath);

/* Prints out debug information on the json context
 * oak - the context to display
 * show_contents - whether to show the json file contents
 * returns: void */
void oakjson_ctx_debug(oakjson_ctx* oak, uint8_t show_contents);

/* Adds a value to our object
 * oak - the context we want to add too
 * type - the type of add, string, object or array
 * name - the name of the value
 * value - the value itself
 * returns: succes (1) or failure (2) */
uint8_t oakjson_ctx_add(oakjson_ctx* oak, oakjson_object_types type,
                        const char* name, const char* value);

/* Frees out oak context
 * oak - the context to destroy
 * returns: success (1) or failure (2) */
uint8_t oakjson_ctx_destroy(oakjson_ctx* oak);

#endif
