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

static void	freedom(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

static	char	*prepare_line_read(char *buffer, char *rest)
{
	char	*temp;
	char	*line_read;

	temp = NULL;
	line_read = ft_strdup(buffer);
	if (!line_read)
		return (NULL);
	if (rest)
	{
		temp = ft_strjoin(rest, line_read);
		if (!temp)
		{
			freedom((void **)&line_read);
			return (NULL);
		}
		line_read = ft_strdup(temp);
		freedom((void **)&temp);
	}
	return (line_read);
}

char	*ft_get_next_line(int fd)
{
	char			*buffer;
	char			*line_read;
	char			*nl_ptr;
	ssize_t			bytes_read;
	static char		*rest;

	line_read = NULL;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (1)
	{
		bytes_read = read (fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1) // ERROR DE LECTURA // 
		{
			freedom((void **)&buffer);
			return (NULL);
		}
		if (bytes_read == 0 && !line_read) // FIN DE LECTURA Y NO TENGO LINE_READ
		{
			freedom((void **)&buffer);
			line_read = ft_strdup(rest);
			freedom((void **)&rest);
			return (line_read);
		}
		buffer[bytes_read] = '\0';
		line_read = prepare_line_read(buffer, rest);
		if (!line_read)
			return (NULL);
		nl_ptr = ft_strchr(line_read, '\n');
		if (nl_ptr || bytes_read == 0)
		{
			nl_ptr[ft_strlen(nl_ptr)] = '\0';
			rest = ft_strdup(nl_ptr + 1);
			line_read = ft_substr(line_read, 0, nl_ptr - line_read);
			freedom((void **)&buffer);
			return (line_read);
		}
	}
	freedom((void **)&buffer);
	return (line_read);
}
