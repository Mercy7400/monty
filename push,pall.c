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

    while (fgets(bus.content, sizeof(bus.content), bus.file) != NULL)
    {
        line_number++;

        if (bus.content[0] == '\n' || bus.content[0] == ' ')
            continue;

        process_opcode(&stack, line_number);
    }

    fclose(bus.file);
    free_stack(stack);

    return EXIT_SUCCESS;
}

