/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 07:18:59 by jbarbate          #+#    #+#             */
/*   Updated: 2022/11/18 11:40:24 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_cut(char *s)
{
	int			i;
	char		*ret;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\n')
		i++;
	ret = malloc(i + 1);
	if (ret == 0)
		return (0);
	ret[i] = '\0';
	ft_strlcpy(ret, s, i + 1);
	return (ret);
}

char	*ft_read(int fd, char *s)
{
	char	*buff;
	int		n;

	buff = malloc(BUFFER_SIZE + 1);
	if (buff == 0)
		return (0);
	n = 1;
	buff[0] = '\0';
	while (ft_isnl(s) < 0 && n != 0)
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (buff[0] == '\0' && s == 0 && n == 0)
			return (free(s), free(buff), NULL);
		buff[BUFFER_SIZE] = '\0';
		if (n < BUFFER_SIZE)
			buff[n] = '\0';
		s = ft_strjoin(s, buff);
		if (s == 0)
			return (free(buff), NULL);
	}
	free(buff);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*s[1025];
	char		*line;
	int			i;

	i = 0;
	if (fd < 0 || read(fd, 0, 0) < 0)
		return (0);
	s[fd] = ft_read(fd, s[fd]);
	if (s[fd] == 0)
		return (NULL);
	if (s[fd][i] != '\0')
	{
		line = ft_cut(s[fd]);
		while (s[fd][i] != '\n' && s[fd][i])
			i++;
		if (s[fd][i] == '\n')
			i++;
		s[fd] = ft_strdup(s[fd], i);
		return (line);
	}
	free(s[fd]);
	return (NULL);
}
