/* Project Euler
 * - JustCoderdev solution to 002 - 2024.02.05
 *
 * Even Fibonacci Numbers
 *   Each new term in the Fibonacci sequence is generated
 *   by adding the previous two terms.
 *   By starting with 1 and 2, the first 10 terms will be:
 *             1, 2, 3, 5, 8, 13, 21, 34, 55, 89
 *
 *   By considering the terms in the Fibonacci sequence
 *   whose values do not exceed four million, find the
 *   sum of the even-valued terms.
 */

#include <stdio.h>

#include "./lib/jctypes.h"


int main(void)
{
	/* 1 2 = 3 */
	/*   2 3 = 5 */
	/*     3 5 = 8 */

	n64 prev = 1, number = 1, next;
	n64 sum = 0, i;

	/* setvbuf(stdout, NULL, _IOFBF, 0); */

	/* for(i = 0; i < (n64)4e6; ++i) */
	for(i = 0; number < (n64)4e6; ++i)
	{
		/* printf("\rCalculating (%lu/%lu) %.2f%%", i, (n64)4e6, i/4e6*100); */

		next = prev + number;
		if(next % 2 == 0) sum += next;

		prev = number;
		number = next;

		/* if(i % 100 == 0) fflush(stdout); */
	}

	printf("\nThe sum of the first 4e6 is %lu\n", sum);

	return 0;
}
