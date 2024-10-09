/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _get_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:09:20 by jaferna2          #+#    #+#             */
/*   Updated: 2024/10/09 11:09:22 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	freedom(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}


char	*get_next_line(int fd)
{
	char			*buffer;
	char			*line_readed;
	char			*eol_ptr;
	ssize_t			bytes_readed;
	static char		*rest;

	line_readed = NULL;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (1)
	{
		bytes_readed = read(fd, buffer, BUFFER_SIZE);
		if (bytes_readed == -1) // FALLO DE LECTURA // 
		{
			freedom((void **)&buffer);
			return (NULL);
		}
		if (bytes_readed == 0) // FIN DE LECTURA // 
		{
			if (rest)
			{
				freedom((void **)&buffer);
				return (rest); 
			}
			return (buffer); 

		}
		buffer[bytes_readed] = '\0';
		// Saved the buffer here // 
		if (!rest) // TO DO freeing this // 
			rest = ft_strdup(buffer);
		else
			rest = ft_strjoin(rest, buffer);
		freedom((void **)buffer);
		eol_ptr = ft_strchr(rest, '\n');
		if (eol_ptr) // FOUNDED eol_ptr
		{
			eol_ptr[ft_strlen(eol_ptr)] = '\0';
			// PREPARE LINE_READED TO RETURN // 
			line_readed = ft_substr(rest, 0, (eol_ptr - line_readed) + 1);
			if (!line_readed)
				return (NULL);
			return (line_readed);
		}
	}
}