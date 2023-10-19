#include "monty.h"

/**
 * stderr_pint - prints error occuring from pint
 * @line_number: line number that the interaction occurs
 * Return: EXIT_FAILURE
 */
int stderr_pint(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * stderr_pop - prints error occuring from pop process
 * @line_number: line number that the interaction occurs
 * Return: EXIT_FAILURE
 */
int stderr_pop(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}
