#include "main.h"
#include <stdio.h>

/**
 * main - prints the numbers from 1 to 100, followed by a new line
 * but for multiples of three prints Fizz instead of the number
 * and for the multiples of five prints Buzz
 * Return: Always 0 (Success)
 */

int main(void)
{
	int a;

	for (a = 1; a <= 100; a++)
	{
		if (a % 3 == 0 && a % 5 != 0)
		{
			printf("Fizz\n");
		} else if (a % 5 == 0 && a % 3 != 0)
		{
			printf("Buzz\n");
		} else if (a % 3 == 0 && a % 5 == 0)
		{
			printf("FizzBuzz\n");
		} else if (a == 1)
		{
			printf("%d\n", a);
		} else
		{
			printf("%d\n", a);
		}

	}
	printf("\n");

	return (0);
}
