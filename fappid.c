#include "farsh.h"
/**
 * getppid -prints the current Parent Process ID
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
        pid_t far_ppid;

        far_ppid = getppid();
        printf("%u\n", far_ppid);
        return (0);
}
