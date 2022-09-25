#include "oakjson/oakjson.h"
#include "json-c/json_object.h"
#include <json-c/json.h>
#include <stdlib.h>
#include <log.h>

oakjson_ctx* oakjson_ctx_create() {
  oakjson_ctx* oak  = malloc(sizeof(oakjson_ctx));
  oak->file         = malloc(sizeof(&oak->file));
  oak->file->object = json_object_new_object();
  return oak;
}

uint8_t oakjson_create_object(oakjson_ctx* oak, const char* filepath) {
  oak->file->object = json_object_new_object();

  if (!oak->file->object) {
    log_error("Failed to construct json object");
    return 1;
  }

  if (json_object_to_file(filepath, oak->file->object)) {
    log_error("Failed to save file: %s\n", filepath);
    return 1;
  }

  return 0;
}

uint8_t oakjson_ctx_add(oakjson_ctx* oak, oakjson_object_types type,
                        const char* name, const char* value) {
  switch (type) {
    case STRING: {
      json_object_object_add(oak->file->object, name,
                             json_object_new_string(value));
    }
    case ARRAY:
      // TODO(ethan): Implement soon as pls :)
      return 0;
    default:
      return 0;
  }
}

void oakjson_ctx_debug(oakjson_ctx* oak, uint8_t show_contents) {
  if (show_contents) {
    log_debug("Content: %s\n", json_object_to_json_string_ext(
                                   oak->file->object, JSON_C_TO_STRING_PRETTY));
  }
  log_debug("PATH: %s\nSIZE: %d\n", oak->file->filepath, oak->file->file_size);
}

uint8_t oakjson_ctx_destroy(oakjson_ctx* oak) {
  if (!oak) {
    log_error("No oak context to free\n");
    return 1;
  }

  if (oak->file) {
    free(oak->file);
  }

  if (oak->file->object) {
    json_object_put(oak->file->object);
  }

  free(oak);
  return 0;
}
