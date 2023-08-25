#include "monty.h"


int err_usage(void);
int alloc_err(void);
int file_open_err(char *filename);
int unknwn_opcode_err(char *opcode, unsigned int line_number);
int u_int_err(unsigned int line_number);

/**
 * err_usage - this prints usage error messages
 * Return: (EXIT_FAILURE) always
 */

int err_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * alloc_err - this prints malloc error messages
 * Return: (EXIT_FAILURE) always
 */

int alloc_err(void)
{
	fprintf(stderr, "ERROR: malloc failed\n");
	return (EXIT_FAILURE);
}


/**
 * file_open_err - this prints file opening error messages with file name
 * @filename: the name of file that failed to open
 * Return: (EXIT_FAILURE) always
 */

int file_open_err(char *filename)
{
	fprintf(stderr, "ERROR: Can't open file %s\n", filename);
	return (EXIT_FAILURE);
}


/**
 * unknwn_opcode_err - this prints unknown instruction error messages
 * @opcode: Opcode where error occurred
 * @line_number: line number in Monty bytecodes file where the error occured
 * Return: (EXIT_FAILURE) always
 */

int unknwn_opcode_err(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}


/**
 * u_int_err - this prints invalid monty_push argument error messages
 * @line_number: line number in Monty bytecodes file where error occurred
 * Return: (EXIT_FAILURE) always
 */

int u_int_err(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	return (EXIT_FAILURE);
}
