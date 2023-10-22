#include "monty.h"

/**
 * stderr_usage - prints error if user does not give a file or more
 * than one argument to the program
 * Return: EXIT_FAILURE
 */
int stderr_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return(EXIT_FAILURE);
}

/**
 * stderr_file_open - prints if its not possible to open provide file
 * @file_nm: file name param
 * Return: EXIT_FAILURE
 */
int stderr_file_open(char *file_nm)
{
	fprintf(stderr, "Error: Can't open file %s\n", file_nm);
	return (EXIT_FAILURE);
}

/**
 * stderr_unknown_opc - prints if unknown error encountered
 * @opcode: opcode that caused error
 * @line_number: line number in where eoor occured in monty byte codes file
 * Return: EXIT_FAILURE
 */
int stderr_unknown_opc(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}

/**
 * stderr_malloc - prints if malloc error encountered
 * Return: EXIT_FAILURE
 */
int stderr_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}

/**
 * int_missing - prints if invalid push error message
 * @line_number: line in monty file that therew error
 * Return: EXIT_FAILURE
 */
int int_missing(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
