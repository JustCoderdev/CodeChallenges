/* Project Euler
 * - JustCoderdev solution to 006 - 2024.02.09
 *
 * Sum Square Difference
 *   The sum of the squares of the first ten natural numbers is:
 *   				1^2 + 2^2 + ... + 10^2 = 385
 *
 *   The square of the sum of the first ten natural numbers is:
 *   				(1 + 2 + ... + 10)^2 = 55^2 = 3025
 *
 *   Hence the difference between the sum of the squares of the first
 *   ten natural numbers and the square of the sum is 3025 - 385 = 2640.
 *
 *
 *   Find the difference between the sum of the squares of the
 *   first one hundred natural numbers and the square of the sum.
 */

#include <stdio.h>

#include <math.h>

#include "./lib/jctypes.h"
#include "./lib/logger.h"

n64 get_sum_of_squares(n64 ceiling)
{
	n64 i, sum = 0;

	for(i = 0; i <= ceiling; ++i)
	{
		sum += pow(i, 2);
	}

	return sum;
}

n64 get_squares_of_sum(n64 ceiling)
{
	n64 i, sum = 0;

	for(i = 0; i <= ceiling; ++i)
	{
		sum += i;
	}

	return pow(sum, 2);
}

int main(void)
{
	n64 squares_sum, sums_square;

	squares_sum = get_sum_of_squares(10);
	sums_square = get_squares_of_sum(10);
	log_assert(squares_sum == 385);
	log_assert(sums_square == 3025);
	printf("The difference of the first ten numbers is %lu\n", sums_square - squares_sum);


	squares_sum = get_sum_of_squares(100);
	sums_square = get_squares_of_sum(100);
	printf("The difference of the first hundred numbers is %lu\n", sums_square - squares_sum);

	return 0;
}
