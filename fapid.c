#include "farsh.h"
/**
 * getpid -prints the current PID
 *@far_pid - pid
 * Return: Always 0.
 *
 */
pid_t getpid(void)
{
	pid_t far_ppid = getppid();
	pid_t far_pid = getpid();

	if (far_pid > 0)
{
	printf("%u\n", far_pid);
}
	else
{
	printf("%u\n", far_ppid);
}
	return (0);
}
