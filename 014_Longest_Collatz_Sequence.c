/* Project Euler
 * - JustCoderdev solution to 014 - 2024.03.15
 *
 *
 * Longest Collatz Sequence
 *   The following iterative sequence is defined
 *   for the set of positive integers:
 *
 *    n -> n / 2 (n is even)
 *    n -> 3n + 1 (n is odd)
 *
 *   Using the rule above and starting with 13,
 *   we generate the following sequence:
 *
 *    13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
 *
 *   It can be seen that this sequence (starting at 13 and finishing at 1)
 *   contains 10 terms. Although it has not been proved yet (Collatz Problem),
 *   it is thought that all starting numbers finish at 1.
 *
 *   Which starting number, under one million, produces the longest chain?
 *   NOTE: Once the chain starts the terms are allowed to go above one million.
 */

#include <stdio.h>

#include "lib/jctypes.h"
#include "lib/logger.h"
#include "lib/sgr.h"

n64 get_next_number(n64 n)
{
	return (n % 2) ? (3 * n + 1) : (n / 2);
}

n64 get_chain_length(n64 seed)
{
	n64 number, links = 1;

	/* printf("[%lu] -> ", seed); */
	for(number = seed; number != 1; ++links)
	{
		number = get_next_number(number);
		/* printf("[%lu] -> ", number); */
	}

	/* printf("\n"); */

	return links;
}

int main(void)
{
	n64 chain_number, chain_len = 0;
	n64 i;

	log_assert(get_chain_length(13) == 10);

	for(i = 13; i < 1e6; ++i)
	{
		n64 links = get_chain_length(i);
		if(links <= chain_len) continue;

		chain_len = links;
		chain_number = i;

		printf(CSI BG_CYAN Z FG_BLACK M "Found new longer chain (%lu)" CSI RESET M "\n",
			   chain_len);
	}

	printf(CSI FG_GREEN M "Longest chain of %lu from %lu\n" CSI RESET M,
		   chain_len,
		   chain_number);

	return 0;
}
