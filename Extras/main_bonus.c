
#include "get_next_line_bonus.h"
#include <fcntl.h>

/*Change the .txt string to another for test*/
int	main(void)
{
	int fd01 = open("bonus01.txt", O_RDONLY); 
	if (fd01 == -1)
	{
		perror("Error opening the file");
		return 1;
	}
	int fd02 = open("bonus02.txt", O_RDONLY); 
	if (fd02 == -1)
	{
		perror("Error opening the file");
		return 1;
	}
	int fd03 = open("bonus03.txt", O_RDONLY); 
	if (fd03 == -1)
	{
		perror("Error opening the file");
		return 1;
	}
	char *linereaded = NULL;
  	int n_lines = 0;
	int n_file = 1;
	while ((linereaded = get_next_line(fd01)) != NULL)
	{
		n_lines++;
    	printf("%d-%d. %s",n_file, n_lines, linereaded);
    	free(linereaded);
	}
	n_file++;
	while ((linereaded = get_next_line(fd02)) != NULL)
	{
		n_lines++;
    	printf("%d-%d. %s",n_file, n_lines, linereaded);
    	free(linereaded);
	}
	n_file++;
	while ((linereaded = get_next_line(fd03)) != NULL)
	{
		n_lines++;
    	printf("%d-%d. %s",n_file, n_lines, linereaded);
    	free(linereaded);
	}
	printf("\ntotal lines readed: %d\n", n_lines);
	close(fd01);
	close(fd02);
	close(fd03);
    return 0;
}
