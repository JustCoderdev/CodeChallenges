/* Project Euler
 * - JustCoderdev solution to 007 - 2024.02.09
 *
 * 10'001st Prime
 *   By listing the first six prime numbers: 2, 3, 5, 7, 11 and 13,
 *   we can see that the 6th prime is 13.
 *
 *   What is the 10'001st prime number?
 */

#include <stdio.h>

#include "./lib/jctypes.h"
#include "./lib/logger.h"


/* Took from solution 003 */
bool isPrime(n64 number)
{
	n64 i;

	if(number < 2) return false;
	for(i = 2; i <= number / 2; ++i)
	{
		if(number % i == 0) return false;
	}

	return true;
}

/* Return 1 if not found */
n64 find_nth_prime(n64 number)
{
	n64 prime = 1;
	n64 i, j;

	for(i = 0; i < number; ++i)
	{
		printf("\rSearching for %luth prime... ", i + 1);

		for(j = ++prime; !isPrime(j); ++j)
			;

		prime = j;
		printf("%lu", prime);
	}
	printf("\n");

	return prime;
}


int main(void)
{
	n64 prime;

	prime = find_nth_prime(6);
	printf("The 6th prime is %lu\n", prime);
	log_assert(prime == 13);

	prime = find_nth_prime(10001);
	printf("The 10001th prime is %lu\n", prime);

	return 0;
}
