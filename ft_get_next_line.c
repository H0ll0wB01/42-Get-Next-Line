/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <jaferna2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:12:40 by jaferna2          #+#    #+#             */
/*   Updated: 2024/10/08 20:15:07 by jaferna2         ###   ########.fr       */
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
	char	*line_read;

	if (rest)
	{
		line_read = ft_strjoin(rest, buffer);
		if (!line_read)
		{
			freedom((void **)&buffer);
			return (NULL);
		}
	}
	else
		line_read = ft_strdup(buffer);
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
		if (bytes_read == -1)
		{
			freedom((void **)&buffer);
			return (NULL);
		}
		if (bytes_read == 0 && !line_read)
		{
			freedom((void **)&buffer);
			line_read = ft_strdup(rest);
			freedom((void **)&rest);
			return (line_read);
		}
		buffer[bytes_read] = '\0';
		line_read = prepare_line_read(buffer, rest); // TO DO Review Malloc with incorrect free
		if (!line_read)
			return (NULL);
		nl_ptr = ft_strchr(line_read, '\n');
		if (nl_ptr || bytes_read == 0)
		{
			nl_ptr[ft_strlen(nl_ptr)] = '\0';
			rest = ft_strdup(nl_ptr + 1); // TO DO Review Malloc with incorrect free
			if (!rest)
				freedom((void **)rest);
			line_read = ft_substr(line_read, 0, nl_ptr - line_read);
			if (!line_read)
				freedom((void **)line_read);
			freedom((void **)&buffer);
			return (line_read);
		}
	}
	freedom((void **)&buffer);
	return (line_read);
}
