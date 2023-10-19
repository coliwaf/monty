#include "monty.h"

char **glob_op = NULL;

/**
 * main - Entry point of the monty intepreter
 * @argc: length of arguments passed to the program
 * @argv: array of strings containing the command line arguments
 * Return: either EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	int resp = EXIT_SUCCESS;
	FILE *file_desc = NULL;

	if (argc != 2)
		return (stderr_usage());

	file_desc = fopen(argv[1], "r");
	if (file_desc == NULL)
		return (stderr_file_open(argv[1]));
	resp = process_monty(file_desc);
	fclose(file_desc);
	return(resp);
}
