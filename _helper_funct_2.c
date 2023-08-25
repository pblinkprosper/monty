#include "monty.h"

void _add(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);

/**
 * _add - adds the top two values of a stack_t linked list.
 * @stack: a pointer to the top mode node of a stack_t linked list.
 * @line_number: the current working line number of a Monty bytecodes file.
 *
 * Description: the result is stored in the second value node
 *              from the top and the top value  is removed.
 *
 * Return: nothing
 */
void _add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		op_token_err(stack_len_err(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	_pop(stack, line_number);
}

/**
 * _sub - subtracts the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: a pointer to the top mode node of a stack_t linked list.
 * @line_number: the current working line number of a Monty bytecodes file.
 *
 * Description: the result is stored in the second value node
 *              from the top and the top value is removed.
 *
 * Return: nothing
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		op_token_err(stack_len_err(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	_pop(stack, line_number);
}

/**
 * _div - divides the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: a pointer to the top mode node of a stack_t linked list.
 * @line_number: the current working line number of a Monty bytecodes file.
 *
 * Description: the result is stored in the second value node
 *              from the top and the top value is removed.
 *
 * Return: nothing
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		op_token_err(stack_len_err(line_number, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		op_token_err(print_div_err(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	_pop(stack, line_number);
}

/**
 * _mul - multiplies the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: a pointer to the top mode node of a stack_t linked list.
 * @line_number: the current working line number of a Monty bytecodes file.
 *
 * Description: the result is stored in the second value node
 *              from the top and the top value is removed.
 *
 * Return: nothing
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		op_token_err(stack_len_err(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	_pop(stack, line_number);
}

/**
 * _mod - computes the modulus of the second value from the
 *             top of a stack_t linked list  by the top value.
 * @stack: a pointer to the top mode node of a stack_t linked list.
 * @line_number: the current working line number of a Monty bytecodes file.
 *
 * Description: the result is stored in the second value node
 *              from the top and the top value is removed.
 *
 * Return: nothing
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		op_token_err(stack_len_err(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		op_token_err(print_div_err(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	_pop(stack, line_number);
}
