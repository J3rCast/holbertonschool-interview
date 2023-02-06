#include "palindrome.h"
/**
 * getLen - get the length of an array.
 *
 * @arr: array to check.
 *
 * Return: return the length of the array.
 */
int getLen(int *arr)
{
	int i = 0;

	while (arr[i] != '\0')
		i++;

	return (i - 1);
}
/**
 * toArray - turns a number into a reverse array
 *
 * @n: number to converts.
 *
 * Return: an inversed array of number
 */
int *toArray(unsigned long n)
{
	static int buffer[20];
	int i = 0;
	unsigned long digit = 0;

	while (n != 0)
	{
		digit = n % 10;
		n = n / 10;
		buffer[i] = digit;
		i++;
	}
	digit = n % 10;
	return (buffer);
}
/**
 * is_palindrome - checks if a number is a palindrome
 *
 * @n: number to checks
 *
 * Return: return 1 if is palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	int *reverseNumber;
	int i = 0;
	int len = 0;

	reverseNumber = toArray(n);
	len = getLen(reverseNumber);
	while (len >= 0)
	{
		if (reverseNumber[len] != reverseNumber[i])
			return (0);
		len--;
		i++;
	}
	return (1);
}
