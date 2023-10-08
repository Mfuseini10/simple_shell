#include "farsh.h"

/**
 *
 *
 *
 *
 */

int main(int ac, char **av)
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
