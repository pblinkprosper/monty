

#include "monty.h"

void _stack(stack_t **stack, unsigned int line_number);
void _queue(stack_t **stack, unsigned int line_number);
void _rotl(stack_t **stack, unsigned int line_number);
void _rotr(stack_t **stack, unsigned int line_number);

/**
 * _stack - this function converts a queue to a stack.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Return: nothing
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * _queue - function that converts a stack to a queue.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Return: nothing
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}

/**
 * _rotl - rotates the top value of a stack_t linked list to the bottom.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Return: nothing
 */
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *start, *end;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	start = (*stack)->next;
	end = (*stack)->next;
	while (end->next != NULL)
		end = end->next;

	start->next->prev = *stack;
	(*stack)->next = start->next;
	end->next = start;
	start->next = NULL;
	start->prev = end;

	(void)line_number;
}

/**
 * _rotr - rotates the bottom value of a stack_t linked list to the top.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Return: nothing
 */
void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *start, *end;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	start = (*stack)->next;
	end = (*stack)->next;
	while (end->next != NULL)
		end = end->next;

	end->prev->next = NULL;
	(*stack)->next = end;
	end->prev = *stack;
	end->next = start;
	start->prev = end;

	(void)line_number;
}
