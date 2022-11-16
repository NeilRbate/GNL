/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 07:18:59 by jbarbate          #+#    #+#             */
/*   Updated: 2022/11/16 18:00:54 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_cut(char *s)
{
	int		i;
	char		*ret;

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
	char	*buff;
	char	*ret;
	char	*stock;
	int	n;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == 0)
		return (0);
	buff[BUFFER_SIZE] = '\0';
	stock = buff;
	n = read(fd, buff, BUFFER_SIZE);
	ret = buff;
	while (ft_isnl(ret) < 0 && n != 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		n = read(fd, buff, BUFFER_SIZE);
		buff[BUFFER_SIZE] = '\0';
		stock = ret;
		ret = ft_strjoin(stock, buff);
		if (ret == 0)
			return (0);
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*stock;
	char		*line;
	int		i;

	i = 0;
	if (fd < 0 || read(fd, 0, 0) < 0)
		return (0);
	if (s == 0)
		s = ft_read(fd);
	else
	{
		stock = ft_read(fd);
		s = ft_strjoin(s, stock);
	}
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
	return (0);
}
