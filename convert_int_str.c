#include "monty.h"

/**
 * _abs - returns absolute value of integer
 * @i: int param
 * Return: unsigned int
 */
unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * get_numb_base_len - returns buffer length of an unsigned int
 * @numb: number param
 * @base: base param
 * Return: Length in int
 */
int get_numb_base_len(unsigned int numb, unsigned int base)
{
	int len = 1;
	
	while (numb > base - 1)
	{
		len++;
		numb /= base;
	}
	return (len);
}

/**
 * fetch_int - pointer to new int string
 * @num: parameter
 * Return: Null if Malloc fails pr new pointer
 */
char *fetch_int(int num)
{
	long num_l = 0;
	int length = 0;
	char *res;
	unsigned int temp;

	temp = _abs(num);

	length = get_numb_base_len(temp, 10);

	if (num < 0 || num_l < 0)
		length++;

	res = malloc(length + 1);
	if (!res)
		return (NULL);

	fill_numb_base_buffer(temp, 10, res, length);
	if (num < 0 || num_l < 0)
		res[0] = '-';

	return (res);
}

/**
 * fill_numb_base_buff - propagates buffer with numbers to base 36
 * @num: numb to convert
 * @base: base used in conversion upto base 36
 * @buff: buffer to fill
 * @buff_size: buffer size
 */
void fill_numb_base_buffer(unsigned int num, unsigned int base,
		char *buff, int buff_size)
{
	int rem;
	int i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;

		if (rem > 9)
			buff[i] = rem + 87;
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}
