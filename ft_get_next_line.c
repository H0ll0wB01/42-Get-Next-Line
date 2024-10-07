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
	ssize_t			bytes_read;
	static char		*rest;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (1) // Lectura del archivo // 
	{
		bytes_read = read (fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0 && !rest)
		{
			free (buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		line_read = ft_strdup(buffer);
		if (rest) // Resto almaceando anteriormente // 
		{
			line_read = ft_strjoin(rest, line_read); // Añado el resto a line_readed //
			free (rest);
			rest = NULL;
		}
		nl_ptr = ft_strchr(line_read, '\n');
		if (nl_ptr) // Se encuentra un EOL //
		{
			nl_ptr[ft_strlen(nl_ptr)] = '\0';
			rest = ft_strdup(nl_ptr + 1);
			line_read = ft_substr(line_read, 0, nl_ptr - line_read);
			free(buffer);
			return (line_read);
		}
		free(nl_ptr);
	}
	free (buffer);
	return (line_read);
}