

// #include "get_next_line.h"
// static char	*obtain_buffer_to_opperate(fd)
// {

// }
// char	*get_next_line(int fd)
// {
// 	char		*buffer;
// 	char		*line_readed;
// 	ssize_t		*bytes_readed;
// 	static char	*saved_rest;

// 	line_readed = NULL;
// 	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
// 	while (1)
// 	{
// 		bytes_readed = read(fd, buffer, BUFFER_SIZE);
// 		if (bytes_readed == -1)
// 		{
// 			if(saved_rest)
// 				free(saved_rest);
// 			free(buffer);
// 			return (NULL);
// 		}
// 		else
// 		{
			
// 		}
// 	}
// }