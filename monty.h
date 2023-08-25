#ifndef MONTY_H
#define MONTY_H

int err_usage(void);
int alloc_err(void);
int file_open_err(char *filename);
int unknwn_opcode_err(char *opcode, unsigned int line_number);
int u_int_err(unsigned int line_number);
int pop_error(unsigned int line_number);
int pint_error(unsigned int line_number);
int short_stack_error(unsigned int line_number, char *op);
int div_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *message);


#endif 
