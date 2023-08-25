#include "monty.h"

int stack_len_err(unsigned int line_number, char *op);
int print_empty_stack_err(unsigned int line_number);
int p_pop_err(unsigned int line_number);
int print_div_err(unsigned int line_number);
int print_pchar_err(unsigned int line_number, char *message);

/**
 * p_pop_err - this prints pop error messages for empty stacks
 * @line_number: line number in script where error occured
 * Return: (EXIT_FAILURE) always
 */

int p_pop_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}


/**
 * print_empty_stack_err - this prints error messages for empty
 * stacks when using pint
 * @line_number: line number in Monty bytecodes file where error occurred
 * Return: (EXIT_FAILURE) always
 */

int print_empty_stack_err(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}


/**
 * stack_len_err - this prints monty math function error messages
 * for stacks/queues smaller than two nodes
 * @line_number: line number in Monty bytecodes file where error occurred
 * @op: Operation where the error occurred
 * Return: (EXIT_FAILURE) always
 */

int stack_len_err(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}


/**
 * print_div_err - this prints division error messages for division by 0
 * @line_number: line number in Monty bytecodes file where error occurred
 * Return: (EXIT_FAILURE) always
 */

int print_div_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * print_pchar_err - this prints pchar error messages for empty stacks
 * empty stacks and non-character values
 * @line_number: line number in Monty bytecodes file where error occurred
 * @message: the corresponding error message to print
 * Return: (EXIT_FAILURE) always
 */

int print_pchar_err(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}
