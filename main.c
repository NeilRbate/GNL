
#include "get_next_line.h"
#include <fcntl.h>


int main(void)
{
	int n = open("test.txt", O_RDONLY);
	char *s = get_next_line(n);
	while (s != 0)
	{
		printf("%s", s);
		s = get_next_line(n);
	}
	printf("%s", s);
	close(n);

	return (0);
}
