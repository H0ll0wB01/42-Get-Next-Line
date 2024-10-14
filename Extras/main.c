#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int fd = open("test01.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening the file");
		return 1;
	}
	// To test here;
	char *linereaded = NULL;
  	int n_lines = 0;
	while ((linereaded = get_next_line(fd)) != NULL)
	{
		n_lines++;
    	printf("%d. %s", n_lines, linereaded);
    	free(linereaded);
	}
	printf("\ntotal lines readed: %d\n", n_lines);
	close(fd);
    return 0;
}
