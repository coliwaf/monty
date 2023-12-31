#include "monty.h"

/**
 * mnt_push - function pushes to a stack_t stack
 * @stack: top mode node of stack
 * @line_number: current line in monty bytecodes file
 */
void mnt_push(stack_t **stack, unsigned int line_number)
{
	int i;
	stack_t *tmp, *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		set_token_error(stderr_malloc());
		return;
	}

	if (glob_op[1] == NULL)
	{
		set_token_error(int_missing(line_number));
		return;
	}

	for (i = 0; glob_op[1][i]; i++)
	{
		if (glob_op[1][i] == '-' && i == 0)
			continue;
		if (glob_op[1][i] < '0' || glob_op[1][i] > '9')
		{
			set_token_error(int_missing(line_number));
			return;
		}
	}
	
	new->n = atoi(glob_op[1]);
	
	if (mode_confirm(*stack) == STACK)
	{
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;

		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
}

/**
 * mnt_pall - prints all chars of stack_t list
 * @stack: the top mst node in the list
 * @line_number: curent working line in the code
 */
void mnt_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->next;

	while(temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}

	(void)line_number;
}

/**
 * mnt_pint - prints top element of stack_t list
 * @stack: the top most node in the list
 * @line_number: current working line in code
 */
void mnt_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp =  (*stack)->next;

	if (temp == NULL)
	{
		set_token_error(stderr_pint(line_number));
		return;
	}

	printf("%d\n", temp->n);
}

/**
 * mnt_pop - removes top element of stack_t list
 * @stack: the top most element pointer
 * @line_number: current execution working line in code
 */
void mnt_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		set_token_error(stderr_pop(line_number));
		return;
	}

	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * mnt_swap - swaps top two elements of stack_t list
 * @stack: top most element pointer
 * @line_number: current execution working line in the code
 */
void mnt_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *stck;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_token_error(stderr_short_stack(line_number, "swap"));
		return;
	}

	stck = (*stack)->next->next;
	(*stack)->next->next = stck->next;
	(*stack)->next->prev = stck;
	
	if (stck->next)
		stck->next->prev = (*stack)->next;
	stck->next = (*stack)->next;
	stck->prev = *stack;
	(*stack)->next = stck;
}
