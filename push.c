#include "monty.h"
/**
 * push - pushes new node to the top of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: the number of a line of the file
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
stack_t *node;
char *numb;
numb = strtok(NULL, MELIMS);
if (numb == NULL)
{
printf("L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
node = malloc(sizeof(stack_t));
if (node == NULL)
{
printf("Error: malloc failed\n");
exit(EXIT_FAILURE);
}
node->n = atoi(numb);
node->prev = NULL;
node->next = *stack;
if (*stack != NULL)
(*stack)->prev = node;
*stack = node;
}