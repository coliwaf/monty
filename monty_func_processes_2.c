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
	int calc;
	
	if (stack == NULL || *stack == NULL || *stack->next == NULL)
	{
		set_token_error(stderr_short_stack(line_number, "sub"));
		return;
	}
	
	(*stack) = (*stack)->next;
	calc = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = calc;
	mnt_pop(stack, line_number);
}

/**
 * mnt_div - divides the top two elements of stack_t list
 * @stack: top most elent's pointer
 * @line_number: current execution's working line in bytecode
 */
void mnt_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next->next == NULL || (*stack)->next == NULL)
	{
		set_token_error(stderr_short_stack(line_number, "div"));
		return;
	}
	if((*stack)->next->n == 0)
	{
		set_token_error(stderr_div(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	mnt_pop(stack, line_number);
}
