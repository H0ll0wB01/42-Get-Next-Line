#include <fcntl.h>
#include "get_next_line.h"


int	main(void)
{
	// int	fd = open("example.txt", O_RDWR | O_CREAT | O_TRUNC, 0755);
    // if (fd == -1) 
	// {
	// 	perror("Error opening the file");
    //     return 1;
    // }
	// write (fd, "HELLO\nWorld\n!Im\nGod", 22);
	// close (fd);

	// fd = open("example.txt", O_RDONLY);
	// if (fd == -1)
	// {
	// 	perror("Error opening the file");
	// 	return 1;
	// }
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
    	printf("%d. %s\n", n_lines, linereaded);
    	free(linereaded);
	}
	printf("total lines readed: %d\n", n_lines);
	close(fd);
    return 0;
}
