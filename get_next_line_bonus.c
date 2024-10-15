/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:52:28 by jaferna2          #+#    #+#             */
/*   Updated: 2024/10/15 09:52:28 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*obtain_rest_with_nl(int fd, char *rest)
{
	char	*buffer;
	int		b_readed;

	buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	b_readed = 1;
	while (!ft_strchr(buffer, '\n') && b_readed != 0)
	{
		b_readed = read(fd, buffer, BUFFER_SIZE);
		if (b_readed == -1)
			return (free(buffer), free(rest), NULL);
		buffer[b_readed] = '\0';
		rest = ft_strjoin(rest, buffer);
		if (!rest)
			return (free(buffer), NULL);
	}
	free (buffer);
	return (rest);
}

static char	*obtain_line_to_eol(char *rest)
{
	int		i;
	char	*line_to_return;

	i = 0;
	if (!rest[i])
		return (NULL);
	while (rest[i] && rest[i] != '\n')
		i++;
	line_to_return = (char *)ft_calloc(sizeof(char), (i + 2));
	if (!line_to_return)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
	{
		line_to_return[i] = rest[i];
		i++;
	}
	if (rest[i] == '\n')
	{
		line_to_return[i] = rest[i];
		i++;
	}
	return (line_to_return);
}

static char	*update_rest(char *rest)
{
	char	*new_rest;
	int		i;
	int		j;

	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (!rest[i])
	{
		free (rest);
		return (NULL);
	}
	new_rest = (char *)ft_calloc(sizeof(char), ft_strlen(rest) - i + 1);
	if (!new_rest)
		return (NULL);
	i++;
	j = 0;
	while (rest[i])
		new_rest[j++] = rest[i++];
	free(rest);
	return (new_rest);
}

char	*get_next_line(int fd)
{
	char		*line_readed;
	static char	*rest[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest[fd] = obtain_rest_with_nl(fd, rest[fd]);
	if (!rest[fd])
		return (NULL);
	line_readed = obtain_line_to_eol(rest[fd]);
	rest[fd] = update_rest(rest[fd]);
	return (line_readed);
}
