/* Project Euler
 * - JustCoderdev solution to 015 - 2024.06.18
 *
 *
 * Lattice Paths
 *   Starting in the top left corner of a 2x2 grid, and only being
 *   able to move to the right and down, there are exactly 6 routes
 *   to the bottom right corner...
 *
 *   How many such routes are there throught a 20x20 grid?
 */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef unsigned char     n8;  /* %u or %c */
typedef unsigned short    n16; /* %u */
typedef unsigned int      n32; /* %u */
typedef unsigned long int n64; /* %lu */


/*
 * 2 L + 2 R
 *
 *  0 1 2 3
 *  4*3*2*1 = 6 * 4
 *
 *   / 4
 *
 *    0   1   2   3
 * 0  L - L - R - R
 * 1  L - R - R - L
 * 2  L - R - L - R
 * 3  R - L - R - L
 * 4  R - L - L - R
 * 5  R - R - L - L
 *
 * */

n64 factorial(n8 n)
{
	n64 res = 1;
	n16 i;

	for(i = 0; i < n; ++i)
		res *= n - i;

	return res;
}

n64 getRoutesFor(n8 square_side)
{
	const n8 DSQUARE = 2 * square_side;
	n64 res = 1;
	n16 i;

	for(i = 0; i < DSQUARE; ++i)
	{
		res *= DSQUARE - i;
	}

	res /= factorial(square_side);

	return res;
}


int main(void)
{
	n64 routes = getRoutesFor(2);
	printf("There are %lu routes in a 2x2 grid\n", routes);
	assert(routes == 6);

	routes = getRoutesFor(20);
	printf("There are %lu routes in a 20x20 grid\n", routes);

	return 0;
}
