#include "logger.h"

#include <stdlib.h>

#include <errno.h>
#include <string.h>
#include <time.h>

#include "sgr.h"

void log_fatal_(char *msg, char *file, int line)
{
	/* clang-format off */
	fprintf(stderr,
			/* CSI RESET Z BOLD    Z BG_MAGENTA Z FG_WHITE    M " FATAL " */
			CSI RESET Z BOLD Z BG_BLACK Z FG_WHITE M " FATAL "
			CSI RESET Z FG_BR_BLACK                M " [%s:%d] "
			CSI RESET                              M "%s\n",
			file, line, msg);
	/* clang-format on */

	exit(1);
}

void log_errno_(char *msg, int error_code, char *file, int line)
{
	/* clang-format off */
	fprintf(stderr,
			CSI RESET Z BOLD Z FG_WHITE Z FG_RED M "ERROR"
			CSI RESET Z FG_BR_BLACK              M " [%s:%d] "
			CSI RESET                            M "%s \\ \n"
			CSI UNDERLINE                        M "errno(%d) message"
			CSI RESET                            M ": %s\n",
			 file, line, msg, error_code, strerror(error_code));
	/* clang-format on */
}

void log_assert_(bool assertion,
				 char *expression,
				 char *file_name,
				 n64 file_line)
{

	if(assertion) return;

	/* clang-format off */
	fprintf(stderr,
			CSI RESET Z BOLD Z BG_RED Z FG_BLACK M " ASSERT "
			CSI RESET Z FG_BR_BLACK              M " [%s"
			CSI RESET Z FG_CYAN                  M ":"
			CSI RESET Z FG_BR_BLACK              M  "%lu] "
			CSI RESET                            M "Assertion failed: \"%s\"\n",
			file_name, file_line, expression);
	/* clang-format on */

	exit(1);
}
