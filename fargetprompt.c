#include "farsh.h"
/**
 * getpid -prints the current PID
 *@far_pid - pid
 *
 * Return: Always 0.
 */
pid_t getpid(void)
{
	pid_t far_pid;

	far_pid = getpid();
	printf("%u\n", far_pid);
	return (0);
}

/**
 * getppid -prints the current Parent Process ID
 *
 * Return: Always 0.
 */
pid_t getppid(void)
{
	pid_t far_ppid;

	far_ppid = getppid();
	printf("%u\n", far_ppid);
	return (0);
}

/**
 *main - a fuction
 *fasum - Adds arguments
 *atoi - converts aphas to nums
 *@ac - argument count
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

/**
 *size_t- the size of buffer
 *stdin - standard input
 *
 *Return - 0
 */
ssize_t getline(char **lineptr, size_t *n, FILE *stdin)
{
	size_t num = 0;
	char *bufa = NULL;

	printf("farsh $");
	getline(&bufa, &num, stdin);
	printf("%s", bufa);
	printf("size of buffer: %ld\n", num);

	free(bufa);
	return (0);
}
