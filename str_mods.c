
#include <stdlib.h>

char *int_val(int n);
unsigned int _abs(int);
int base_len(unsigned int n, unsigned int base);
void base_buff(unsigned int n, unsigned int base,
		       char *buff, int buff_size);

/**
 * int_val - extraact the value of the int character pointer
 * @n: number to be converted to string
 *
 * Return: Ptr to newly created string and NULL if malloc fails.
 */
char *int_val(int n)
{
	unsigned int tmp;
	int len = 0;
	long num_l = 0;
	char *ret;

	tmp = _abs(n);
	len = base_len(tmp, 10);

	if (n < 0 || num_l < 0)
		len++;
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);

	base_buff(tmp, 10, ret, len);
	if (n < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * _abs - gets the absolute value of an integer
 * @i: integer to get absolute value of
 *
 * Return: abs of i
 */
unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * base_len - gets length of a buffer
 * @n: number to get length needed for
 * @base: base of number used by buffer
 *
 * Return: integer containing length of buffer needed (doesn't contain null bt)
 */
int base_len(unsigned int n, unsigned int base)
{
	int len = 1;

	while (n > base - 1)
	{
		len++;
		n /= base;
	}
	return (len);
}

/**
 * base_buff - fills buffer with correct numbers up to base 36
 * @n: number to convert to given base
 * @base: base of number used in conversion, only works up to base 36
 * @buff: buffer to fill with result of conversion
 * @buff_size: size of buffer in bytes
 *
 * Return: always void.
 */
void base_buff(unsigned int n, unsigned int base,
			char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = n % base;
		if (rem > 9) /* return lowercase ascii val representation */
			buff[i] = rem + 87; /* 10 will be a, 11 = b, ... */
		else
			buff[i] = rem + '0';
		n /= base;
		i--;
	}
}
