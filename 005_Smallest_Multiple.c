/* Project Euler
 * - JustCoderdev solution to 005 - 2024.02.08
 *
 * Smallest Multiple
 *   2520 is the smallest number that can be divided
 *   by each of the numbers from 1 to 10 without any remainder.
 *
 *   What is the smallest positive number that is evenly
 *   divisible by all of the numbers from 1 to 20?
 */

#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#include "./lib/jctypes.h"
#include "./lib/logger.h"

bool checkDivisibility(n64 number, n64 floor, n64 ceiling)
{
	n64 i;

	for(i = floor; i <= ceiling; ++i)
	{
		if(number % i != 0)
		{
			printf("%lu is not divisible by %lu!\n", number, i);
			return false;
		}
	}

	return true;
}

/* Return the smallest multiple from 2 to <ceil> */
n64 get_smallest_multiple(n64 ceil)
{
	n64 *map = malloc(sizeof(n64) * (ceil - 1));
	n64 *tmp_map = malloc(sizeof(n64) * (ceil - 1));
	n64 result, i, num;

	/* 2    3    4    5    6    7    8    9    10  */
	/* 2    3   2*2   5   2*3   7  2*2*2 3*3  2*5 */
	/*                          7  2*2*2 3*3    5 */
	/* 7 * 8 * 9 * 5 = 2520  */

	/* 1    2    3   2*2   5   2*3   7  2*2*2 3*3  2*5 */

	/* map
	 * 2: 3
	 * 3: 2
	 * 4:
	 * 5: 1
	 * 6:
	 * 7: 1
	 * 8:
	 * 9:
	 * 10
	 * */

	/* 0 initialize arrays */
	for(i = 0; i < (ceil - 1); ++i)
	{
		map[i] = 0;
		tmp_map[i] = 0;

		/* printf("\t(%lu)", i + 2); */
	}
	/* printf("\n"); */


	for(num = 2; num <= ceil; ++num)
	{
		n64 number = num;
		/* printf("[%lu]: \t", num); */
		/* printf("Examining [%lu] \n", num); */

		/* Get prime factor of number */
		for(i = 2; i <= number; ++i)
		{
			/* printf(" > %lu <= %lu\n", i, number); */
			if(number == 1) break;
			if(number % i == 0)
			{
				/* printf("%lu is divisible by %lu, (new: %lu)\n", number, i,
				 * number / i); */
				number /= i;

				tmp_map[i - 2] += 1;
				i = 1;
			}
		}

		/* printf("===\n"); */


		/* Compare numbers and add bigger numbers */
		for(i = 0; i < (ceil - 1); ++i)
		{
			/* printf("  tmp_map[%lu](%lu) = %lu\n", i, i + 2, tmp_map[i]); */
			/* printf("%lu\t", tmp_map[i]); */

			if(tmp_map[i] > map[i]) map[i] = tmp_map[i];

			/* Reset tmp array */
			tmp_map[i] = 0;
		}

		/* printf("\n"); */
	}


	/* printf("  result *= pow((i + 2), map[i])\n"); */
	result = 1;
	for(i = 0; i < (ceil - 1); ++i)
	{
		result *= pow((i + 2), map[i]);
		/* printf("    %lu *= pow((%lu + 2), %lu)\t\t=\t%lu\n", result, i,
		 * map[i], (n64)pow((i + 2), map[i])); */
	}

	free(map);
	free(tmp_map);
	return result;
}

int main(void)
{
	n64 number;

	number = get_smallest_multiple(10);
	printf("%lu is divisible by all numbers between 1 and 10\n", number);
	log_assert(number == 2520);


	number = get_smallest_multiple(20);
	printf("%lu is divisible by all numbers between 1 and 20\n", number);

	return 0;
}
