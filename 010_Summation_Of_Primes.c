/* Project Euler
 * - JustCoderdev solution to 010 - 2024.02.13
 *
 * Summation of Primes
 *   The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *
 *   Find the sum of all the primes below two million.
 */

#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include <signal.h>

#include "./lib/jctypes.h"
#include "./lib/logger.h"
#include "./lib/sgr.h"

void buff_print(n64 *buffer, n64 length)
{
	n64 i;

	printf("[ ");
	for(i = 0; i < length; ++i)
	{
		printf("%lu,\t", buffer[i]);
	}

	printf("]\n");
}


/* Using Dijkstra's prime algorithm */
#define PRIME_BUFF_MAX 128000000
static n64 primes[PRIME_BUFF_MAX];
static n64 pool[PRIME_BUFF_MAX];

static n64 prime_count = 0;
static n64 prime = 1;
n64 prime_get_next()
{
	n64 smallest, smallest_index, i;

	do
	{
		/* 1. Get next number */
		prime++;
		/* printf(CSI FG_CYAN M "PRIME: %lu\n" CSI RESET M, prime); */
		/* buff_print(primes, prime_count); */
		/* buff_print(pool, prime_count); */
		/* printf("__\n"); */

		/* 2. Compare it with the smallest multiple in the pool */
		for(smallest = -1, smallest_index = 0, i = 0; i < prime_count; ++i)
		{
			if(pool[i] <= smallest)
			{
				smallest = pool[i];
				smallest_index = i;

				if(prime == smallest)
				{
					pool[smallest_index] += primes[smallest_index];
					/* buff_print(pool, prime_count); */
				}
			};
		}

		/* printf(CSI FG_MAGENTA M "SMALLEST: %lu\n" CSI RESET M, smallest);
		 */

		/* 2. If                                           */
		if(prime < smallest)
		{
			/* smaller: add to prime pool                  */
			primes[prime_count] = prime;
			pool[prime_count] = pow(prime, 2);
			prime_count++;

			if(prime_count == PRIME_BUFF_MAX) {
				printf("Reached max buffer\n");
				exit(1);
			}

			/* printf(CSI SWAP M); */
			/* buff_print(primes, prime_count); */
			/* printf(CSI RESET M); */

			/* buff_print(pool, prime_count); */
			/* printf("----------\n"); */

			return prime;
		}
	}
	while(1);

	/* printf("----------\n"); */

	return 0;
}

void on_kill(int code)
{
	printf("\nExit requested, code: %d\n", code);

	/* buff_print(primes, prime_count); */
	/* printf(CSI FG_CYAN M "\n\n\n\n\n" CSI RESET M); */
	/* buff_print(pool, prime_count); */
	/* printf("----------\n"); */
	printf(CSI FG_CYAN M "Calculated %lu primes, last: %lu\n\n" CSI RESET M, prime_count, prime);
	abort();
}

int main(void)
{
#define CEILING ((n64)2e6)
	n64 prime = 0, sum;
		/* , i = 0; */

	signal(SIGINT, on_kill);

	for(sum = 0; prime <= CEILING; prime = prime_get_next())
	{
		/* if(i++ % 200 == 0) printf("\rCalculating... (%lu/10000)", i); */
		sum += prime;
	}

	printf("The sum of primes below %lu is %lu\n", CEILING, sum);
	printf(CSI FG_CYAN M "Calculated %lu primes, last: %lu\n\n" CSI RESET M, prime_count, prime);

	return 0;
}
