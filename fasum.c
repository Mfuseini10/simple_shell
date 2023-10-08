#include "farsh.h"
/**
 * main - a fuction
 *fasum - Adds arguments
 *atoi - converts aphas to nums
 * @ac - argument count
 *@av - argument vector
 * Return - always 0
 */

int main(int ac, char **av)
{
	int z;
	int fasum = 0;

	printf("argument count= %d\n", ac);
	printf("argument vector= argv[]\n");

	for (z = 1; z < ac; z++)
	{
		printf("argv[%d]= %s\n", z, av[z]);
		fasum += atoi(av[z]);
	}
	printf("addition is %d", fasum);
	return (0);
}
