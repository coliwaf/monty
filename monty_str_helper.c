#include "monty.h"

/**
 * strtow - separates string to words
 * @str: string input param
 * @delims: paramater arguments
 * Return: array of pointers of each word
 */
char **strtow(char *str, char *delims)
{
	int word_len, n, count, i = 0;
	char **words = NULL;

	if (str == NULL || !*str)
		return (NULL);

	count = count_words(str, delims);
	if(count == 0)
		return (NULL);

	words = malloc((count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	while (i < count)
	{
		word_len = length_w(str, delims);
		if (if_delim(*str, delims))
		{
			str = word_after(str, delims);
		}
		words[i] = malloc((word_len + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < word_len)
		{
			words[i][n] = *(str + n);
			n++;
		}
		words[i][n] = '\0';
		str = word_after(str, delims);
		i++;
	}
	words[i] = NULL;
	return (words);
}

/**
 * count_words - counts words in a string
 * @str: input string param
 * @delims: delimiter constraints
 * Return: count
 */
int count_words(char *str, char *delims)
{
	int count = 0, i = 0, remaining = 1;

	while(*(str + i))
	{
		if (if_delim(str[i], delims))
			remaining = 1;
		else if (remaining)
		{
			remaining = 0;
			count++;
		}
		i++;
	}
	return (count);
}

/**
 * if_delim - checks for delim char
 * @chr: char to check against
 * @delims: delimeter constraints
 * Return: 1 if success or 0 on failure
 */
int if_delim(char chr, char *delims)
{
	int i = 0;

	while(delims[i])
	{
		if (delims[i] == chr)
			return (1);

		i++;
	}
	return (0);
}

/**
 * length_w - returns length of current word
 * @str: word to get length of
 * @delims: delimeter constraints
 * Return: word length
 */
int length_w(char *str, char *delims)
{
	int i = 0, len = 0, remaining = 1;

	while (*(str + i))
	{
		if (if_delim(str[i], delims))
			remaining = 1;
		else if (remaining)
			len++;

		if (len > 0 && if_delim(str[i], delims))
			break;
		i++;
	}
	return (len);
}

/**
 * word_after - returns next word in the string
 * @str: string param to get word from
 * @delims: params to constraint to
 * Return: str when found 
 */
char *word_after(char *str, char *delims)
{
	int remaining = 0, i = 0;

	while (*(str + 1))
	{
		if (if_delim(str[i], delims))
			remaining = 1;
		else if (remaining)
			break;
		i++;
	}
	return (str + i);
}
