/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:12:40 by jaferna2          #+#    #+#             */
/*   Updated: 2024/10/04 12:15:18 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_next_line(int fd)
{
	char			*buffer;
	char			*line_read;
	char			*nl_ptr;
	size_t			bytes_read;
	static	char	*rest;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1)); 
	if (!buffer)
		return (NULL);
	while (1) // Lectura del archivo // 
	{
		bytes_read = read (fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0) 
		{
			free (buffer);
			printf("Error de lectura \n");
			return (NULL);
		}
		if (bytes_read == 0) // finalización de lectura //
		{
			free (buffer);
			return (line_read);
		}
		buffer[bytes_read] = '\0';
		if (rest) // Resto almaceando anteriormente // 
		{
			line_read = ft_strjoin(line_read, rest);
			free (rest);
			rest = NULL;
		}
		nl_ptr = ft_strchr(buffer, '\n');
		if (nl_ptr) // Se encuentra un EOL // 
		{
			nl_ptr[ft_strlen(nl_ptr)] = '\0';
			rest = ft_strdup(nl_ptr + 1);
			line_read = ft_strjoin(line_read, buffer);
			free(buffer);
			return (line_read);	
		}
		line_read = ft_strjoin(line_read, buffer); // Si no se encuentra EOL guardo en line_read todo // 
	}
	free (buffer);
	return (line_read);
}

