#ifndef BASE_HEADER
#define BASE_HEADER
#include <log.h>
#include <stdlib.h>

#ifndef OAK_UNIMPLEMENTED
#define OAK_UNIMPLEMENTED(X) \
  log_error("%s", #X);       \
  exit(EXIT_FAILURE);
#endif

#endif
