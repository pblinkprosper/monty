#include "monty.h"

void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);

/**
 * _push - pushes a value to a stack_t linked list.
 * @stack: a pointer to the top mode node of a stack_t linked list.
 * @line_number: the current working line number of a Monty bytecodes file.
 *
 * Return: nothing
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		op_token_err(alloc_err());
		return;
	}

	if (op_toks[1] == NULL)
	{
		op_token_err(u_int_err(line_number));
		return;
	}

	for (i = 0; op_toks[1][i]; i++)
	{
		if (op_toks[1][i] == '-' && i == 0)
			continue;
		if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
		{
			op_token_err(u_int_err(line_number));
			return;
		}
	}
	new->n = atoi(op_toks[1]);

	if (stack_check(*stack) == STACK) /* STACK mode insert at front */
	{
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else /* QUEUE mode insert at end */
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
 * _pall - prints the values of a stack_t linked list.
 * @stack: a pointer to the top mode node of a stack_t linked list.
 * @line_number: the current working line number of a Monty bytecodes file.
 *
 * Return: nothing
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}

/**
 * _pint - prints the top value of a stack_t linked list.
 * @stack: a pointer to the top mode node of a stack_t linked list.
 * @line_number: the current working line number of a Monty bytecodes file.
 *
 * Return: nothing
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		op_token_err(print_empty_stack_err(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}


/**
 * _pop - removes the top value element of a stack_t linked list.
 * @stack: a pointer to the top mode node of a stack_t linked list.
 * @line_number: the current working line number of a Monty bytecodes file.
 *
 * Return: nothing
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		op_token_err(p_pop_err(line_number));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
 * _swap - swaps the top two value elements of a stack_t linked list.
 * @stack: a pointer to the top mode node of a stack_t linked list.
 * @line_number: the current working line number of a Monty bytecodes file.
 *
 * Return: nothing
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		op_token_err(stack_len_err(line_number, "swap"));
		return;
	}

	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}
