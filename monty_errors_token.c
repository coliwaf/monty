#include "monty.h"

/**
 * set_token_error - sets glob_op last element as error code
 * @code: parameter to process
 */
void set_token_error(int code)
{
	int i = 0, toklen = 0;
	char *exitstr = NULL, **newtokn = NULL;
	
	toklen = token_len();
	newtokn = malloc(sizeof(char *) * (toklen + 2));
	
	if (!glob_op)
	{
		stderr_malloc();
		return;
	}
	
	while (i < toklen)
	{
		newtokn[i] = glob_op[i];
		i++;
	}
	
	exitstr = fetch_int(code);
	if (!exitstr)
	{
		free(newtokn);
		stderr_malloc();
		return;
	}
	
	newtokn[i++] = exitstr;
	newtokn[i] = NULL;
	free(glob_op);
	glob_op = newtokn;
}
