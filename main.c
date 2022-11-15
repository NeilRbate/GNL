
#include "get_next_line.h"
#include <fcntl.h>


int main(void)
{
	int n = open("test.txt", O_RDONLY);
	char *s = get_next_line(n);
	while (s != 0)
	{
		printf("line -> \n |%s|\n", s);
		s = get_next_line(n);

	}
	close(n);

	return (0);
}
