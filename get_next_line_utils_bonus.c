/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:13:11 by jaferna2          #+#    #+#             */
/*   Updated: 2024/10/15 09:52:59 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			s;
	void			*ptr;
	size_t			i;
	unsigned char	*p;

	s = nmemb * size;
	ptr = malloc(s);
	if (!ptr)
		return (NULL);
	p = (unsigned char *) ptr;
	i = 0;
	while (i < s)
	{
		p[i] = '\0';
		i++;
	}
	return (ptr);
}

char	*ft_strdup(const char *s)
{
	size_t	sl;
	char	*ns;
	int		i;

	sl = ft_strlen(s);
	ns = (char *)malloc((sl + 1) * sizeof(char));
	if (!ns)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ns[i] = s[i];
		i++;
	}
	ns[i] = '\0';
	return (ns);
}

char	*ft_strchr(const char *s, int c)
{
	char	*p;
	int		i;

	p = (char *)s;
	i = 0;
	if (!s)
		return (NULL);
	while (p[i])
	{
		if (p[i] == (char)c)
			return ((char *)&p[i]);
		i++;
	}
	if (p[i] == (char)c)
		return ((char *)&p[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	l;
	char	*ns;
	int		i;

	if (!s1)
		s1 = (char *)ft_calloc(sizeof(char), 1);
	if (!s1 || !s2)
		return (NULL);
	l = ft_strlen(s1) + ft_strlen(s2);
	ns = ft_calloc(sizeof(char), (l + 1));
	if (!ns)
		return (NULL);
	i = -1;
	while (s1[++i])
		ns[i] = s1[i];
	while (*s2)
		ns[i++] = *s2++;
	free (s1);
	return (ns);
}
