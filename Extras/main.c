
#include "get_next_line.h"
#include <fcntl.h>

/*Change the .txt string to another for test*/
int	main(void)
{
	int fd = open("el_quijote.txt", O_RDONLY); 
	if (fd == -1)
	{
		perror("Error opening the file");
		return 1;
	}
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
