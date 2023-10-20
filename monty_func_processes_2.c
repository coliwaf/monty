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

/**
 * mnt_nop - function prints nothing and does nothing
 * @stack: topmost element's pointer
 * @line_number: current excecution line in the code
 */
void mnt_nop(__attribute__((unused))stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	;
}

/**
 * mnt_sub - substracts the top two elements of Stack_t list
 * @stack: top most element's pointer
 * @line_number: current executions working line in byte
 */
void mnt_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = (*stack)->next;
	
	if (curr == NULL || curr->next == NULL)
	{
		set_token_error(stderr_short_stack(line_number, "sub"));
		return;
	}

	curr->next->n -= curr->n;
	mnt_pop(stack, line_number);
}
