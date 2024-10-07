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

// Substr strlen strchr //
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l;
	char	*ns;
	int		i;
	int		j;

	l = ft_strlen(s1) + ft_strlen(s2);
	ns = (char *)malloc((l + 1) * sizeof(char));
	if (!ns)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ns[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ns[i] = s2[j];
		i++;
		j++;
	}
	ns[i] = '\0';
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
	ns = (char *) malloc((len + 1) * sizeof(char));
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
	ns[j] = '\0';
	return (ns);
}