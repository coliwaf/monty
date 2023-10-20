#include "monty.h"

/**
 * mnt_add - functions adds top two elements of stack_t list
 * @stack: topmost element's pointer
 * @line_number: current execution working line in the code
 */
void mnt_add(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = (*stack)->next;

	if (curr == NULL || curr->next == NULL)
	{
		set_token_error(stderr_short_stack(line_number, "add"));
		return;
	}

	curr->next->n += curr->n;
	mnt_pop(stack, line_number);
}
