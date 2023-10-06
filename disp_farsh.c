#include <stdio.h>
#include "farsh.h"
/**
 *farsh - The name of the simple shell function to be displayed
 *disp_farsh - The function
 *
 *Return - 0 (EXIT_SUCCESS)
 */

int main(void)
{
	char type_in[MAX_INPUT_SIZE];

	for (;;)
	{
	/**
	 *  Display a simple prompt
	 *  Flush the output buffer to ensure the prompt is displayed
	 */
	printf("farsh $");
	fflush(stdout);
	/**
	 *  Read user input
	 */
	if (fgets(type_in, sizeof(type_in), stdin) == NULL)
	{
	break;
	}
	/**
	 *  Remove trailing newline character
	 */
	type_in[strcspn(type_in, "\n")] = '\0';
	/**
	 * Process the user input (you can add your shell logic here)
	 */
	if (strcmp(type_in, "exit") == 0)
	{
		printf("Exiting the shell.\n");
		break;
	}
	else
	{
		printf("You entered: %s\n", type_in);
	}
	return (EXIT_SUCCES);
}
