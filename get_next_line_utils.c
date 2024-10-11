/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaferna2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:13:11 by jaferna2          #+#    #+#             */
/*   Updated: 2024/10/04 11:05:46 by jaferna2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
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

char	*ft_strdup(char *s)
{
	size_t	sl;
	char	*ns;
	int		i;

	if (!s)
		return (NULL);
	sl = ft_strlen(s);
	ns = ft_calloc((sl + 1), sizeof(char));
	if (!ns)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ns[i] = s[i];
		i++;
	}
	return (ns);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ns;
	char	*aux;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup("\0"));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	ns = (char *) ft_calloc((len + 1), sizeof(char));
	if (!ns)
		return (NULL);
	aux = (char *)s;
	i = start;
	j = 0;
	while (aux[i] && j < len)
	{
		ns[j] = aux[i];
		i++;
		j++;
	}
	return (ns);
}
