#include <fcntl.h>
#include "get_next_line.h"


int	main(void)
{
	int	fd = open("example.txt", O_RDWR | O_CREAT | O_TRUNC, 0755);
    if (fd == -1) 
	{
		perror("Error opening the file");
        return 1;
    }
	write (fd, "HELLO\nWorld\n!", 13);
	close(fd);

	fd = open("example.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening the file");
		return 1;
	}
	// To test here;
	/*char	buffer[BUFFER_SIZE];
	ssize_t bytesRead = read(fd, buffer, sizeof(buffer) -1);
	if (bytesRead == -1)
	{
		perror("Error reading the file");
		close(fd);
		return 1;
	}
	buffer[bytesRead] = '\0';
	printf("text  found: %s\n",  buffer);
	*/
	char *linereaded = NULL;
	
  	while ((linereaded = ft_get_next_line(fd)) != NULL)
	{
		printf("line_readed: %s\n", linereaded);
		free (linereaded);
	}
	close(fd);
    return 0;
}
