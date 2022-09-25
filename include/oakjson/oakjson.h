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
 * @param oak - the the context to set
 * @param filepath - the filepath we wish to set
 * @returns success (0) or failure (1) */
uint8_t oakjson_create_object(oakjson_ctx* oak, const char* filepath);

/* Prints out debug information on the json context
 * @param oak - the context to display
 * @param show_contents - whether to show the json file contents
 * @returns void */
void oakjson_ctx_debug(oakjson_ctx* oak, uint8_t show_contents);

/* Adds a value to our object
 * @param oak - the context we want to add too
 * @param type - the type of add (string, object, array)
 * @param name - the name of the value
 * @param value - the value itself
 * @returns succes (0) or failure (1) */
uint8_t oakjson_ctx_add_string(oakjson_ctx* oak, const char* name,
                               const char* value);

/* Removes a specific json element from the json structure
 * @param oak - the context we want to remove from
 * @param name - the name of the object
 * @param type - the type that we're trying to remove (string, object, array)
 * @returns success (0) or failure (1) */
uint8_t oakjson_ctx_remove_string(oakjson_ctx* oak, const char* name);

/* Adds a value to our object
 * @param oak - the context we want to add too
 * @param type - the type of add (string, object, array)
 * @param name - the name of the value
 * @param value - the value itself
 * @returns succesc (0) or failure (1) */
uint8_t oakjson_ctx_add_array(oakjson_ctx* oak, const char* name,
                              const char* value);

/* Removes a specific json element from the json structure or the whole array
 * @param oak - the context we want to remove from
 * @param name - the name of the array, can be null if remove_whole is true
 * @param remove_whole -
 * whether to remove the whole array returns: success (0) or failure (1)
 * @returns success (0) or failure (1) */
uint8_t oakjson_ctx_remove_array(oakjson_ctx* oak, const char* name,
                                 uint8_t remove_whole);

/* Frees/Destroys our oak context
 * @param oak - the context to destroy
 * @returns success (0) or failure (1) */
uint8_t oakjson_ctx_destroy(oakjson_ctx* oak);

#endif
