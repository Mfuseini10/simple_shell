#include "farsh.h"
/**
 * getpid -prints the current PID
 *@far_pid - pid
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	pid_t far_pid;

	far_pid = getpid();
	printf("%u\n", far_pid);
	return (0);
}
