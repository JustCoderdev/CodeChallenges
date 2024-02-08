#ifndef OUTILS_LOGGER_H
#define OUTILS_LOGGER_H

#include "jctypes.h"
#include <errno.h>


#define log_fatal(msg) log_fatal_(msg, __FILE__, __LINE__)

#define log_errno(msg)	 log_errno_(msg, errno, __FILE__, __LINE__)
#define log_assert(EXPR) log_assert_(EXPR, #EXPR, __FILE__, __LINE__)

/* #define log_time_start() log_time_start_(__FILE__, __LINE__) */
/* #define log_time_end()   log_time_end_(__FILE__, __LINE__) */


extern void log_fatal_(char *msg, char *file, int line);

extern void log_errno_(char *msg, int error_code, char *file, int line);
extern void log_assert_(bool assertion, char *expression, char *file_name, n64 file_line);

/* extern void log_time_start_(char* file_name, n64 file_line); */
/* extern void log_time_end_(char* file_name, n64 file_line); */



#endif /* OUTILS_LOGGER_H */
