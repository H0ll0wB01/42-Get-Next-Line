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

static char	*update_rest(char *rest, char *new_str)
{
	rest = ft_strdup(new_str);
	return (rest);
}


static char	*ft_strjoin_custom(char *s1, char *s2)
{
	size_t	l;
	char	*ns;
	int		i;

	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		s2 = ft_strdup("");
	l = ft_strlen(s1) + ft_strlen(s2);
	ns = ft_calloc((l + 1), sizeof(char));
	if (!ns)
	{
		free (s1);
		free (s2);
		return (NULL);
	}
	i = -1;
	while (s1[++i])
		ns[i] = s1[i];
	while (*s2)
		ns[i++] = *s2++;
	freedom((void **)&s1);
	return (ns);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	char			*line_readed;
	char			*eol_ptr;
	ssize_t			bytes_readed;
	static char		*rest = NULL;

	line_readed = NULL;
	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (1) 	// READ FROM FILE DESCRIPTOR //
	{
		bytes_readed = read(fd, buffer, BUFFER_SIZE);
		if (bytes_readed == -1) // HANDLE READ ERROR // 
		{
			if (rest)
				freedom((void **)&rest);
			freedom((void **)&buffer);
			return (NULL);
		}
		if (bytes_readed == 0) // EOF // 
		{
			freedom((void **)&buffer);
			if (!rest || !*rest) // NO REST SAVED // 
			{
				freedom((void **)&rest);
				return (NULL);
			}
			eol_ptr = ft_strchr(rest, '\n');
			if (eol_ptr) // FOUNDED EOL // 
			{
				*eol_ptr = '\0';
				line_readed = ft_substr(rest, 0, (eol_ptr - rest) + 1);
				if (!line_readed)
					return (NULL);
				rest = update_rest(rest, eol_ptr + 1);
				freedom((void **)&buffer);
				return (line_readed);
			}
			else // NO EOL FOUNDED // 
			{
				line_readed = ft_strdup(rest);
				freedom((void **)&rest);
				return (line_readed);
			}
		}
		else 
			buffer[bytes_readed] = '\0';


		// ----------------------------------------------------------------------- //

		// HANDLE REST //

		rest = ft_strjoin_custom(rest, buffer);
		if (!rest)
			freedom((void **)&rest);
		
		// ----------------------------------------------------------------------- //

		// SEARCH FOR EOL //
		eol_ptr = ft_strchr(rest, '\n');
		if (eol_ptr) // FOUNDED EOL //
		{
			*eol_ptr = '\0';
			line_readed = ft_substr(rest, 0, (eol_ptr - rest) + 1);
			if (!line_readed)
				return (NULL);
			rest = update_rest(rest, eol_ptr + 1);
			freedom((void **)&buffer);
			return (line_readed);
		}
	}
}

// single line with EOL Leak //

// Normal use leak //