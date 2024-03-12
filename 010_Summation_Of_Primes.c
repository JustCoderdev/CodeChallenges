/* Project Euler
 * - JustCoderdev solution to 010 - 2024.02.13
 *
 * Summation of Primes
 *   The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *
 *   Find the sum of all the primes below two million.
 *
 * MAC:
 * 	- Minimal debug time: 6:31.47
 * 	- No printing - time: 6:01.75
 *
 * ACER:
 * 	- No printing - time: 11:00.94
 * 	- O3 Optimized - time: 2:38.96
 */

#include <stdio.h>
#include <stdlib.h>

/* #include <math.h> */
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
#define PRIME_BUFF_MAX 152000
static n64 primes[PRIME_BUFF_MAX];
static n64 pool[PRIME_BUFF_MAX];

static n64 g_prime_count = 0;
static n64 g_prime = 1;
n64 prime_get_next()
{
	n64 smallest, smallest_index, i;

	do
	{
		/* 1. Get next number */
		g_prime++;
		/* printf(CSI FG_CYAN M "PRIME: %lu\n" CSI RESET M, g_prime); */
		/* buff_print(primes, g_prime_count); */
		/* buff_print(pool, g_prime_count); */
		/* printf("__\n"); */

		/* 2. Compare it with the smallest multiple in the pool */
		/* smallest is unsigned, so -1 is the highest number possible */
		for(smallest = -1, smallest_index = 0, i = 0; i < g_prime_count; ++i)
		{
			if(pool[i] <= smallest)
			{
				smallest = pool[i];
				smallest_index = i;

				if(g_prime == smallest)
				{
					pool[smallest_index] += primes[smallest_index];
					/* buff_print(pool, prime_count); */
				}
			}
		}

		/* printf(CSI FG_MAGENTA M "SMALLEST: %lu\n" CSI RESET M, smallest); */

		/* 2. If                                           */
		if(g_prime < smallest)
		{
			/* smaller: add to prime pool                  */
			primes[g_prime_count] = g_prime;
			pool[g_prime_count] = g_prime * g_prime;
			g_prime_count++;

			/* if(g_prime_count == PRIME_BUFF_MAX) { */
			/* 	printf("Reached max buffer\n"); */
			/* 	exit(1); */
			/* } */

			/* printf(CSI SWAP M); */
			/* buff_print(primes, prime_count); */
			/* printf(CSI RESET M); */

			/* buff_print(pool, prime_count); */
			/* printf("----------\n"); */

			return g_prime;
		}
	}
	while(1);

	/* printf("----------\n"); */

	return 0;
}

void on_kill(int code)
{
	printf(CSI FG_RED M "\nExit requested, code: %d\n" CSI RESET M, code);

	/* buff_print(primes, prime_count); */
	/* printf(CSI FG_CYAN M "\n\n\n\n\n" CSI RESET M); */
	/* buff_print(pool, prime_count); */
	/* printf("----------\n"); */
	printf(CSI FG_CYAN M "Calculated %lu primes, last: %lu\n\n" CSI RESET M, g_prime_count, g_prime);
	abort();
}

int main(void)
{
#define CEILING ((n64)2e6)
	n64 prime = 0, sum;

	signal(SIGINT, on_kill);

	for(sum = 0; prime <= CEILING; prime = prime_get_next())
	{
		sum += prime;
	}

	printf(CSI FG_GREEN M "The sum of primes below %lu is %lu\n" CSI RESET M, CEILING, sum);
	printf(CSI FG_CYAN M "Calculated %lu primes, last: %lu\n\n" CSI RESET M, g_prime_count, prime);

	return 0;
}
