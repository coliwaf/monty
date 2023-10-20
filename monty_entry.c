#include "monty.h"

/**
 * check_empty_line - check if returned line from getline only 
 * contains delimiters
 * @ln: line param as a pointer
 * @delims: array of delimiters chars
 * Return: 1 if only contains delimeters otherwise return 0
 */
int check_empty_line(char *ln, char *delims)
{
	int i, j;

	for (i = 0; ln[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (ln[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}
	
	return (1);
}

/**
 * process_monty - main program loop to execute the Monty script
 * @file_desc: file param to execute
 * Return: either EXIT_SUCCESS or the error code
 */
int process_monty(FILE *file_desc)
{
	char *ln = NULL;
	stack_t *stack = NULL;
	size_t exit_as = EXIT_SUCCESS, len = 0;
	unsigned int len_prev_tok = 0, ln_num = 0;
	void (*opc_f)(stack_t**, unsigned int);

	if (new_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&ln, &len, file_desc) != -1)
	{
		ln_num++;
		glob_op = strtow(ln, DELIMS);
		if (glob_op == NULL)
		{
			if (check_empty_line(ln, DELIMS))
				continue;
			free_stck(&stack);
			return (stderr_malloc());
		}
		else if (glob_op[0][0] == '#')
		{
			free_tkns();
			continue;
		}
		opc_f = get_opc_f(glob_op[0]);
		if (opc_f == NULL)
		{
			free_stck(&stack);
			exit_as = stderr_unknown_opc(glob_op[0], ln_num);
			free_tkns();
			break;
		}
		len_prev_tok = token_len();
		opc_f(&stack, ln_num);
		if (token_len() != len_prev_tok)
		{
			if (glob_op && glob_op[len_prev_tok])
				exit_as = atoi(glob_op[len_prev_tok]);
			else
				exit_as = EXIT_FAILURE;
			free_tkns();
			break;
		}
		free_tkns();
	}
	free_stck(&stack);

	if (ln && *ln == 0)
	{
		free(ln);
		return (stderr_malloc());
	}
	
	free(ln);
	return (exit_as);
}

/**
 * token_len - Fetchs the length of glob_op
 * Return: glob_op len as int
 */
unsigned int token_len(void)
{
	unsigned int toks_len = 0;

	while (glob_op[toks_len])
		toks_len++;

	return (toks_len);
}

/**
 * get_opc_f - fetches corresponding func;tion to provided opcode
 * @opcode: parameter to match
 * Return: pointer to corresponding func
 */
void (*get_opc_f(char *opcode))(stack_t**, unsigned int)
{
	instruction_t opc_funcs[] = {
		{"push", mnt_push},
		{"pall", mnt_pall},
		{"pint", mnt_pint},
		{"pop", mnt_pop},
		{"swap", mnt_swap},
		{NULL, NULL}
	};
	int i;

	for (i = 0; opc_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, opc_funcs[i].opcode) == 0)
			return (opc_funcs[i].f);
	}
	return (NULL);
}
