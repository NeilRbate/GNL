
#include "get_next_line.h"
#include <fcntl.h>


int main(void)
{
	int n = open("test.txt", O_RDONLY);
	char *s = get_next_line(n);
	printf("line 1 -> \n |%s|\n", s);
	s = get_next_line(n);
	printf("line 2 -> \n |%s|\n", s);

	return (0);
}
