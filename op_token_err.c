
#include "monty.h"

/**
 * op_token_err - Sets last element of op_toks to be an error code.
 * @error_code: Integer to store as a string in op_toks.
 */
void op_token_err(int error_code)
{
	int len = 0, i = 0;
	char *exit_str = NULL;
	char **new_toks = NULL;

	len = token_len();
	new_toks = malloc(sizeof(char *) * (len + 2));
	if (!op_toks)
	{
		alloc_err();
		return;
	}
	while (i < len)
	{
		new_toks[i] = op_toks[i];
		i++;
	}
	exit_str = int_val(error_code);
	if (!exit_str)
	{
		free(new_toks);
		alloc_err();
		return;
	}
	new_toks[i++] = exit_str;
	new_toks[i] = NULL;
	free(op_toks);
	op_toks = new_toks;
}
