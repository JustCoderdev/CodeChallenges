/* Project Euler
 * - JustCoderdev solution to 008 - 2024.02.10
 *
 * Largest Product in a Series
 *   The four adjacent digits in the 1000-digit number
 *   that have the greatest product are 9 x 9 x 8 x 9 = 5832.
 *      7...0
 *
 *   Find the thirteen adjacent digits in the 1000-digit
 *   number that have the greatest product.
 *
 *   What is the value of this product?
 */

#include <stdio.h>
#include <stdlib.h>

#include "./lib/jctypes.h"
#include "./lib/logger.h"

#define STREAM_LEN 1000
const char * const digits_raw[] = {
	"73167176531330624919225119674426574742355349194934",
	"96983520312774506326239578318016984801869478851843",
	"85861560789112949495459501737958331952853208805511",
	"12540698747158523863050715693290963295227443043557",
	"66896648950445244523161731856403098711121722383113",
	"62229893423380308135336276614282806444486645238749",
	"30358907296290491560440772390713810515859307960866",
	"70172427121883998797908792274921901699720888093776",
	"65727333001053367881220235421809751254540594752243",
	"52584907711670556013604839586446706324415722155397",
	"53697817977846174064955149290862569321978468622482",
	"83972241375657056057490261407972968652414535100474",
	"82166370484403199890008895243450658541227588666881",
	"16427171479924442928230863465674813919123162824586",
	"17866458359124566529476545682848912883142607690042",
	"24219022671055626321111109370544217506941658960408",
	"07198403850962455444362981230987879927244284909188",
	"84580156166097919133875499200524063689912560717606",
	"05886116467109405077541002256983155200055935729725",
	"71636269561882670428252483600823257530420752963450",
};

n64 find_greatest_product(const char * const stream, n64 sample_count)
{
	n64 greatest_product = 0, product;
	n64 i, j;

	for(i = 0; i < (STREAM_LEN - sample_count); ++i)
	{
		product = 1;

		/* printf("\r"); */

		for(j = 0; j < sample_count; ++j)
		{
			/* printf(" * %c", stream[i + j]); */
			product *= stream[i + j] - '0';
		}

		/* printf(" = %lu", product); */

		if(product > greatest_product)
		{
			greatest_product = product;
			/* printf("\nFound new greatest product (%lu)\n", greatest_product); */
		}
	}

	return greatest_product;
}

int main(void)
{
	char *digits_stream = (char *)malloc(STREAM_LEN * sizeof(char));
	n64 product;
	n64 i, j;

	for(i = 0; i < 20; ++i)
	{
		for(j = 0; j < 50; ++j)
		{
			digits_stream[i * 50 + j] = digits_raw[i][j];
		}
	}

	product = find_greatest_product(digits_stream, 4);
	printf("The gretest continous product for 4 digits is %lu\n", product);
	log_assert(product == 5832);

	product = find_greatest_product(digits_stream, 13);
	printf("The gretest continous product for 13 digits is %lu\n", product);

	return 0;
}
