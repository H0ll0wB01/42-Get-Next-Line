/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:52:28 by jaferna2          #+#    #+#             */
/*   Updated: 2024/10/14 10:52:30 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		{
			free(buffer);
			return (NULL);
		}
		buffer[b_readed] = '\0';
		rest = ft_strjoin(rest, buffer);
		if (!rest)
		{
			free(buffer);
			return (NULL);
		}
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
	line_to_return[i] = '\0';
	return (line_to_return);
}

static char	*update_rest(char *rest)
{
	char	*new_rest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (!rest[i])
	{
		free (rest);
		return (NULL);
	}
	new_rest = (char *)ft_calloc(sizeof(char), ft_strlen(rest) - i);
	if (!new_rest)
		return (NULL);
	i++;
	while (rest[i])
	{
		new_rest[j] = rest[i];
		i++;
		j++;
	}
	free(rest);
	return (new_rest);
}

char	*get_next_line(int fd)
{
	char		*line_readed;
	static char	*rest;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest = obtain_rest_with_nl(fd, rest);
	if (!rest)
		return (NULL);
	line_readed = obtain_line_to_eol(rest);
	rest = update_rest(rest);
	return (line_readed);
}
