#ifndef MONTY_H
#define MONTY_H

#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define DELIMS " \n\t\a\b"
#define STACK 0
#define QUEUE 1

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Global opcode token */
extern char **glob_op;

/* Primary funcs */
int new_stack(stack_t **stack);
int process_monty(FILE *file_desc);
void free_stck(stack_t **stack);
void free_tkns(void);
void (*get_opc_f(char *opcode))(stack_t**, unsigned int);
unsigned int token_len(void);
int mode_confirm(stack_t *stack);

/* Error Funcs */
int stderr_usage(void);
int stderr_file_open(char *file_nm);
int stderr_malloc(void);
int stderr_unknown_opc(char *opcode, unsigned int line_number);
void set_token_error(int code);
int int_missing(unsigned int line_number);
int stderr_pint(unsigned int line_number);
int stderr_pop(unsigned int line_number);

/* custon std library functions */
char **strtow(char *str, char *delims);
char *fetch_int(int num);

/* helpers */
int check_empty_line(char*ln, char *delims);
int count_words(char *str, char *delims);
int length_w(char *str, char *delims);
int if_delim(char chr, char *delims);
char *word_after(char *str, char *delims);

/* monty functions */
void mnt_push(stack_t **stack, unsigned int line_number);
void mnt_pall(stack_t **stack, unsigned int line_number);
void mnt_pint(stack_t **stack, unsigned int line_number);
void mnt_pop(stack_t **stack, unsigned int line_number);

void fill_numb_base_buffer(unsigned int num, unsigned int base,char *buff, int buff_size);

#endif
