/* Project Euler
 * - JustCoderdev solution to 004 - 2024.02.06
 *
 * Largest Palindrome Number
 *   A palindromic number reads the same both ways.
 *   The largest palindrome made from the product of two
 *   2-digit numbers is 9009 = 91 x 99.
 *
 *   Find the largest palindrome made from the product
 *   of two 3-digit numbers.
 */

#include <stdio.h>
#include <stdlib.h>

#include <math.h>

#include "./lib/jctypes.h"
#include "./lib/logger.h"
#include "./lib/sgr.h"

n64 get_digit_count(n64 number)
{
	n64 digit_count = 0;
	do
	{
		number /= 10;
		digit_count++;
	}
	while(number != 0);

	return digit_count;
}

bool isPalindrome(n64 number)
{
	n64 digits_len = get_digit_count(number);
	char *digits = malloc(sizeof(char) * digits_len);
	n64 i;

	if(digits == NULL) log_errno("Error mallocating...");

	/* printf("%lu --> [ ", number); */

	for(i = digits_len; i > 0; --i)
	{
		digits[i - 1] = (char)('0' + (number % 10));
		number /= 10;
	}

	/* for(i = 0; i < digits_len; ++i) */
	/* 	printf("%c, ", digits[i]); */

	/* printf("]\n"); */

	/* 104 (3) */
	for(i = 0; i < digits_len / 2; ++i)
	{
		n8 first_digit = digits[i];
		n8 last_digit = digits[digits_len - i - 1];

		if(first_digit != last_digit) return false;

		/* printf("%u == %u\n", first_digit, last_digit); */
	}

	free(digits);
	return true;
}

/* Return 0 if not found */
n64 largest_palindrome_in_range(n64 floor, n64 ceil)
{
	n64 number, largest_number = 0;
	n64 i, j;

	for(i = floor; i < ceil; ++i)
	{
		for(j = floor; j < ceil; ++j)
		{
			number = i * j;

			if(isPalindrome(number) && number > largest_number)
				largest_number = number;

			printf("\rCalculating... [%lu * %lu] (%lu/%lu)",
				   i,
				   j,
				   (ceil + ceil) - (i + j),
				   ceil + ceil);
		}
	}

	return largest_number;
}

int main(void)
{
	n64 number;

	/* 2-digit numbers is 9009 = 91 x 99. */
	number = largest_palindrome_in_range(10, 100);
	log_assert(number == 9009);
	printf("\nNumber %lu is the largest palindome from 2 digit numbers\n\n",
		   number);


	number = largest_palindrome_in_range(100, 1000);
	printf("\nNumber %lu is the largest palindome from 3 digit numbers\n\n",
		   number);

	return 0;
}
