/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 07:18:59 by jbarbate          #+#    #+#             */
/*   Updated: 2022/11/16 09:40:35 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_cut(char *s)
{
	int		i;
	char	*ret;

	i = 0;
	if (s[0] != '\n')
	{
		while (s[i] != '\n' && s[i])
			i++;
		if (s[i] == '\n')
			i++;
		ret = malloc(sizeof(char) * i + 1);
		if (ret == 0)
			return (0);
		ret[i] = '\0';
		ft_strlcpy(ret, s, i + 1);
	}
	if (s[0] == '\n')
	{
		ret = malloc(sizeof(char) * 2);
		if (ret == 0)
			return (0);
		ret[0] = '\n';
		ret[1] = '\0';
	}
	return (ret);
}

char	*ft_read(int fd)
{
	char	s[BUFFER_SIZE + 1];
	char	*ret;
	char	*stock;
	int		n;

	ft_bzero(s, BUFFER_SIZE + 1);
	n = read(fd, s, BUFFER_SIZE);
	ret = ft_strdup(s);
	if (ret == 0)
		return (0);
	if (n != 0)
	{
		while (n != 0)
		{
			ft_bzero(s, BUFFER_SIZE + 1);
			n = read(fd, s, BUFFER_SIZE);
			stock = ft_strjoin(ret, s);
			if (stock == 0)
				return (free(ret), NULL);
			if (n != 0)
				ret = stock;
		}
		return (stock);
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*line;
	int			i;

	i = 0;
	if (fd < 0 || read(fd, 0, 0) < 0)
		return (0);
	if (s == 0)
		s = ft_read(fd);
	if (s[i] != '\0')
	{
		line = ft_cut(s);
		while (s[i] != '\n' && s[i])
			i++;
		if (s[i] == '\n')
			i++;
		s += i;
		return (line);
	}
	if (s == '\0')
		free(s);
	return (0);
}
