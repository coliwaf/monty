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

/**
 * stderr_short_stack - prints error occuring if stacks are smaller 
 * 			than two nodes
 * @line_number: line number where the interaction occurs
 * @identifier: specifies the explicit trigger operation
 * Return: EXIT_FAILURE
 */
int stderr_short_stack(unsigned int line_number, char *identifier)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, identifier);
	return (EXIT_FAILURE);
}

/**
 * stderr_div - prints errors occuring from the division process
 * @line_number: line number that the interaction occurs
 * Return: EXIT_FAILURE
 */
int stderr_div(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}
