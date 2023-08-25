#include "monty.h"
#include <string.h>

void tokens_free(void);
unsigned int token_len(void);
int check_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
ssize_t getline();
int _monty(FILE *script_fd);

/**
 * tokens_free - frees the global op_toks array of strings.
 */
void tokens_free(void)
{
	size_t i = 0;

	if (op_toks == NULL)
		return;

	for (i = 0; op_toks[i]; i++)
		free(op_toks[i]);

	free(op_toks);
}

/**
 * token_len - gets the length of current op_toks.
 *
 * Return: length of current op_toks (as int).
 */
unsigned int token_len(void)
{
	unsigned int toks_len = 0;

	while (op_toks[toks_len])
		toks_len++;
	return (toks_len);
}

/**
 * check_line - checks if a line read from getline only contains delimiters
 * @line: a pointer to the line.
 * @delims: a string of delimiter characters.
 *
 * Return: if the line only contains delimiters - 1.
 *         Otherwise - 0.
 */
int check_line(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}

/**
 * get_op_func - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the corresponding function.
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}

	return (NULL);
}

/**
 * _monty - primary function to execute a Monty bytecodes script.
 * @script_fd: file descriptor for an open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int _monty(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0, old_toklen = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (stack_init(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, script_fd) != -1)
	{
		line_number++;
		op_toks = strtow(line, DELIMS);
		if (op_toks == NULL)
		{
			if (check_line(line, DELIMS))
				continue;
			stack_free(&stack);
			return (alloc_err());
		}
		else if (op_toks[0][0] == '#') /* comment line */
		{
			tokens_free();
			continue;
		}
		op_func = get_op_func(op_toks[0]);
		if (op_func == NULL)
		{
			stack_free(&stack);
			exit_status = unknwn_opcode_err(op_toks[0], line_number);
			tokens_free();
			break;
		}
		old_toklen = token_len();
		op_func(&stack, line_number);
		if (token_len() != old_toklen)
		{
			if (op_toks && op_toks[old_toklen])
				exit_status = atoi(op_toks[old_toklen]);
			else
				exit_status = EXIT_FAILURE;
			tokens_free();
			break;
		}
		tokens_free();
	}
	stack_free(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (alloc_err());
	}

	free(line);
	return (exit_status);
}
