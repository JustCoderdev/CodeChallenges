/* Project Euler
 * - JustCoderdev solution to 009 - 2024.02.11
 *
 * Special Pythagorean Triplet
 *   A Pythagorean triplet is a set of three natural
 *   numbers, a < b < c, for which, a^2 + b^2 = c^2
 *
 *   For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 *   There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 *   Find the product abc.
 */

#include <stdio.h>

#include <math.h>

#include "./lib/jctypes.h"
#include "./lib/logger.h"
#include "./lib/sgr.h"

int main(void)
{
	double a, b, c;
	n64 i = 0;

#define MAX 1000
	for(a = 1; a < MAX; ++a)
	{
		for(b = a + 1; b < MAX; ++b)
		{
			c = pow(a, 2) + pow(b, 2);
			c = sqrt(c);

			if((n64)c != c) continue;

			if(a + b + c == 1000)
			{
				printf(CSI SWAP M "[%lu] "
								  "%.0lf + %.0lf + %.0lf = %.0lf\n" CSI RESET M,
					   i++,
					   a,
					   b,
					   c,
					   a + b + c);

				printf("The product of abc where the sum is 1000 is %lu\n", (n64)a * (n64)b * (n64)c);

				return 0;
			}

			printf("[%lu] %.0lf + %.0lf + %.0lf = %.0lf \n",
				   i++,
				   a,
				   b,
				   c,
				   a + b + c);
		}
	}

	/* a < b < c */
	/* a^2 + b^2 = c^2 */
	/* a + b + c = 1000 */

	/* a + b + c = 1000 */

	return 0;
}
