/* push,pall.c */
#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Monty bytecode interpreter
 * @argc: argument count
 * @argv: argument vector
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
    stack_t *stack = NULL;
    unsigned int line_number = 0;
    char *file_path;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    file_path = argv[1];
    bus.file = fopen(file_path, "r");
    if (!bus.file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", file_path);
        return EXIT_FAILURE;
    }

    while (getline(&bus.content, &bus.size, bus.file) != -1)
    {
        line_number++;

        if (bus.content[0] == '\n' || bus.content[0] == ' ')
            continue;

        process_opcode(&stack, line_number);
    }

    fclose(bus.file);
    free(bus.content);
    free_stack(stack);

    return EXIT_SUCCESS;
}

/**
 * process_opcode - Process Monty bytecode instruction
 * @stack: pointer to the stack
 * @line_number: line number
 */
void process_opcode(stack_t **stack, unsigned int line_number)
{
    char *opcode, *arg;

    opcode = strtok(bus.content, " \t\n");
    if (!opcode)
        return;

    arg = strtok(NULL, " \t\n");

    if (!strcmp(opcode, "push"))
    {
        if (!arg || !is_valid_integer(arg))
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit_with_error();
        }
        push(stack, atoi(arg), line_number);
    }
    else if (!strcmp(opcode, "pall"))
    {
        pall(stack, line_number);
    }
    else
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
        exit_with_error();
    }
}

/**
 * is_valid_integer - Check if a string represents a valid integer
 * @str: string to check
 * Return: 1 if valid integer, 0 otherwise
 */
int is_valid_integer(const char *str)
{
    int i = 0;

    if (str[i] == '-')
        i++;

    for (; str[i] != '\0'; i++)
    {
        if (!isdigit((unsigned char)str[i]))
            return 0;
    }

    return 1;
}

/**
 * exit_with_error - Cleanup and exit with EXIT_FAILURE
 */
void exit_with_error(void)
{
    fclose(bus.file);
    free(bus.content);
    free_stack(bus.stack);
    exit(EXIT_FAILURE);
}

