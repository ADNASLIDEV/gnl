/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aasli <aasli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 10:15:15 by aasli             #+#    #+#             */
/*   Updated: 2021/12/07 13:50:55 by aasli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	update(char *buffer, char **remain, int fd)
{
	char	*tmp;

	if (!remain[fd])
	{
		tmp = ft_strdup(buffer);
		if (!tmp)
			return (0);
		free(remain[fd]);
		remain[fd] = tmp;
	}
	else
	{
		tmp = ft_strjoin(remain[fd], buffer);
		if (!tmp)
			return (0);
		free(remain[fd]);
		remain[fd] = tmp;
	}
	return (1);
}

void	load_buff(int fd, char **remain)
{
	char	buffer[BUFFER_SIZE + 1];
	int		ret;

	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		if (!update(buffer, remain, fd))
			return ;
		if (ft_strchr(remain[fd], '\n'))
			return ;
		ret = read(fd, buffer, BUFFER_SIZE);
	}
}

char	*get_current_line(int fd, char **remain)
{
	char	*tmp;
	char	*line;
	int		i;

	if (!remain[fd] || remain[fd][0] == '\0')
	{
		free(remain[fd]);
		remain[fd] = NULL;
		return (NULL);
	}
	i = 0;
	while (remain[fd][i] != '\0' && remain[fd][i] != '\n')
		i++;
	if (remain[fd][i] == '\n')
		i++;
	line = ft_substr(remain[fd], 0, i);
	tmp = ft_substr(remain[fd], i, ft_strlen(remain[fd]));
	free(remain[fd]);
	remain[fd] = tmp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remain[1024];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE >= 8000000)
		return (NULL);
	if (!remain[fd] || !ft_strchr(remain[fd], '\n'))
		load_buff(fd, remain);
	line = get_current_line(fd, remain);
	return (line);
}
