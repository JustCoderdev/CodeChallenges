/* Project Euler
 * - JustCoderdev solution to 003 - 2024.02.05
 *
 * Largest Prime Factor
 *   The prime factors of 13195 are 5, 7, 13 and 29.
 *   What is the largest prime factor of the number 600,851,475,143?
 */

#include <stdio.h>

#include "./lib/jctypes.h"
#include "./lib/logger.h"

bool isPrime(n64 number) {
	n64 i;

	if(number < 2) return false;
    for (i = 2; i <= number / 2; ++i) {
		if(number % i == 0) return false;
	}

	return true;
}

int get_largest_prime(n64 number)
{
	int largest_prime = -1;
	n64 i;

	for(i = 0; i <= number; ++i)
	{
		n64 prime = i;
		if(!isPrime(prime)) continue;

		printf("\rTesting (%lu/%lu)", prime, number);

		/* printf("Testing %lu with %lu\n", number, prime); */
		if(number % prime == 0)
		{
			number /= prime;
			largest_prime = prime;

			printf("\rMatch with %lu, new number is %lu\n", prime, number);
			if(number == 1) return largest_prime;
		}
	}

	return largest_prime;
}

int main(void)
{
	n64 number = 13195;
	int largest_prime = get_largest_prime(number);
	printf("The largest prime factor of %lu is %d\n\n", number, largest_prime);
	log_assert(largest_prime == 29);

	number = 600851475143;
	largest_prime = get_largest_prime(number);
	printf("The largest prime factor of %lu is %d\n\n", number, largest_prime);

	return 0;
}
