#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Monty bytecode interpreter
 * @argc: argument count
 * @argv: argument vector
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
    stack_t *stack = NULL;
    char *file_path;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return (EXIT_FAILURE);
    }

    file_path = argv[1];
    bus.file = fopen(file_path, "r");

    if (!bus.file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", file_path);
        return (EXIT_FAILURE);
    }

    while (getline(&bus.content, &bus.size, bus.file) != -1)
    {
        line_number++;
        process_opcode(&stack, line_number);
    }

    fclose(bus.file);
    free_stack(stack);
    free(bus.content);

    return (EXIT_SUCCESS);
}

/**
 * process_opcode - process Monty opcodes
 * @stack: pointer to the stack
 * @line_number: current line number
 */
void process_opcode(stack_t **stack, unsigned int line_number)
{
    char *opcode, *arg;

    opcode = strtok(bus.content, " \t\n");

    if (opcode)
    {
        arg = strtok(NULL, " \t\n");

        if (strcmp(opcode, "push") == 0)
        {
            if (arg && is_valid_integer(arg))
                push(stack, atoi(arg));
            else
                exit_with_error(line_number, "usage: push integer");
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall(stack, line_number);
        }
        else if (strcmp(opcode, "pint") == 0)
        {
            pint(stack, line_number);
        }
        else if (strcmp(opcode, "pop") == 0)
        {
            pop(stack, line_number);
        }
        else if (strcmp(opcode, "swap") == 0)
        {
            swap(stack, line_number);
        }
        else if (strcmp(opcode, "add") == 0)
        {
            add(stack, line_number);
        }
        else if (strcmp(opcode, "nop") == 0)
        {
            /* Do nothing for nop */
        }
        else
        {
            exit_with_error(line_number, "unknown instruction");
        }
    }
}

/* Implementations of other opcode functions (push, pall, pint, pop, swap, add, etc.) go here */

/**
 * exit_with_error - print error message and exit with failure status
 * @line_number: current line number
 * @msg: error message
 */
void exit_with_error(unsigned int line_number, const char *msg)
{
    fprintf(stderr, "L%d: %s\n", line_number, msg);
    fclose(bus.file);
    free_stack(bus.stack);
    free(bus.content);
    exit(EXIT_FAILURE);
}

