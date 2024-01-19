#include "monty.h"

/* Global variable to hold data during opcode execution */
struct {

    char *arg;
	  
} data;

/* Function to execute Monty bytecodes */
void monty_execute(char *file_path);

/* Main function */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    monty_execute(argv[1]);

    return EXIT_SUCCESS;
}

/* Function to execute Monty bytecodes from a file */
void monty_execute(char *file_path)
{
    FILE *file = fopen(file_path, "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", file_path);
        exit(EXIT_FAILURE);
    }

    /* Other setup code as needed */

    /* Read lines from the file and execute corresponding opcodes */
    while (/* There are lines in the file */)
    {
        /* Parse the opcode and its argument, if any */
        /* Find the corresponding function in the instruction set */
        /* Execute the function with the stack and line number */
    }

    fclose(file);
}

/* Implementations of opcode functions */

void push(stack_t **stack, unsigned int line_number)
{
    /* Implementation of the push opcode */
}

void pall(stack_t **stack, unsigned int line_number)
{
    /* Implementation of the pall opcode */
}

void pint(stack_t **stack, unsigned int line_number)
{
    /* Implementation of the pint opcode */
}

void pop(stack_t **stack, unsigned int line_number)
{
    /* Implementation of the pop opcode */
}

void swap(stack_t **stack, unsigned int line_number)
{
    /* Implementation of the swap opcode */
}

void add(stack_t **stack, unsigned int line_number)
{
    /* Implementation of the add opcode */
}

void nop(stack_t **stack, unsigned int line_number)
{
    /* Implementation of the nop opcode */
}

