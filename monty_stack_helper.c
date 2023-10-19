#include "monty.h"

/**
 * new_stack - Initialiazes a new stack_t with beninning stack
 * and ending queue nodes
 * @stack: uninitialized stack-t
 * Return: EXIT_SUCCESS otherwise return EXIT_FAILURE
 */
int new_stack(stack_t **stack)
{
	stack_t *stk;

	stk = malloc(sizeof(stack_t));
	if (stk == NULL)
		return (stderr_malloc());

	stk->n = STACK;
	stk->prev = NULL;
	stk->next = NULL;

	*stack = stk;
	return (EXIT_SUCCESS);
}

/**
 * free_stck - Frees the given stack_t stack
 * @stack: pointer to stack top or queue bottom of stack_t
 */
void free_stck(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * free_tkns - Frees global glob_op array of strings
 */
void free_tkns(void)
{
	size_t i = 0;
	if (glob_op == NULL)
		return;

	for (i=0; glob_op[i]; i++)
		free(glob_op[i]);
	free(glob_op);
}

/**
 * mode_confirm - confirms mode of stack_t (stack or queue mode)
 * @stack: points to either top if stack or bottom if queue
 * Return: 0 if is stack, 1 if queue else return 2
 */
int mode_confirm(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
