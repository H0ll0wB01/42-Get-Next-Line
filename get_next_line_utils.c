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

char	*ft_strdup(char *s)
{
	size_t	sl;
	char	*ns;
	int		i;

	if (!s)
		return (NULL);
	sl = ft_strlen(s);
	ns = malloc((sl + 1) * sizeof(char));
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

char	*ft_strjoin_custom(char *s1, char *s2)
{
	size_t	l;
	char	*ns;
	int		i;

	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		s2 = ft_strdup("");
	l = ft_strlen(s1) + ft_strlen(s2);
	ns = malloc((l + 1) * sizeof(char));
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
	ns[i] = '\0';
	free(s1);
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
