/* monty.h */
#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>

/* Define structure for stack */
typedef struct stack_s
{
    int n;
    struct stack_s *next;
} stack_t;

/* Define structure for Monty data bus */
typedef struct monty_bus_s
{
    FILE *file;
    char *content;
    size_t size;
    stack_t *stack;
} monty_bus_t;

extern monty_bus_t bus;

/* Function declarations */
void push(stack_t **stack, int value, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);
int is_valid_integer(const char *str);
void exit_with_error(void);
void process_opcode(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */

