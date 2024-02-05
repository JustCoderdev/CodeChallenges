/* Project Euler
 * - JustCoderdev solution to 001 - 2024.02.02
 *
 * Multiples of 3 or 5
 *   If we list all the natural numbers below 10 that are
 *   multiples of 3 or 5, we get 3, 5, 6 and 9.
 *   The sum of these multiples is 23.
 *   Find the sum of all the multiples of 3 or 5 below 1000.
 */

#include <stdio.h>

#include "./lib/jctypes.h"
#include "./lib/logger.h"


n64 get_sum_of_multiples_below(n64 base, n64 ceiling) {
	n64 sum = 0;
	n64 number = 0, i = 1;

	/* 3 6 9 12 15 18 21 24 27 30 */
	/* 5   10   15   20   25   30 */
	do {
		sum += number;
		/* printf("%lu + ", number); */
		number = base * i++;
	} while(number < ceiling);
	/* putchar('\n'); */

	return sum;
}

int main(void)
{
	n64 sum = 0;

	sum  = get_sum_of_multiples_below(3, 10);
	sum += get_sum_of_multiples_below(5, 10);

	log_assert(sum == 23);
	printf("The sum for 10 is %lu\n", sum);


	sum  = get_sum_of_multiples_below(3, 1000);
	sum += get_sum_of_multiples_below(5, 1000);
	sum -= get_sum_of_multiples_below(15, 1000);

	printf("The sum for 1000 is %lu\n", sum);

	return 0;
}
