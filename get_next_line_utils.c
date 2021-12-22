/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasli <aasli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:15:55 by aasli             #+#    #+#             */
/*   Updated: 2021/12/06 15:25:29 by aasli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	i = 0;
	while (s[i++])
	{
		if ((unsigned char)c == tmp[i])
			return ((char *)tmp + i);
	}
	if (c == '\0')
		return ((char *)tmp + i);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char		*cpy;
	int			size;
	int			i;

	size = ft_strlen(s) + 1;
	cpy = (char *) malloc(size * sizeof(char));
	if (!(cpy))
		return (0);
	i = 0;
	while (s[i])
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*array;
	size_t	i;

	i = 0;
	array = malloc(nmemb * size);
	if (!array)
		return (NULL);
	while (i < size * nmemb)
	{
		array[i] = 0;
		i++;
	}
	return ((void *)array);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof (char)));
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[i] = (char)s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i + j] = (char)s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	new = (char *)malloc(len * sizeof(char) + 1);
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
