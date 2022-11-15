/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 07:18:59 by jbarbate          #+#    #+#             */
/*   Updated: 2022/11/15 14:59:31 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_cut(char *s)
{
	int		i;
	char	*ret;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	ret = malloc(sizeof(char) * i);
	ret[i] = '\0';
	i--;
	while (i >= 0)
	{
		ret[i] = s[i];
		i--;
	}
	return (ret);
}

char	*ft_read(int fd)
{
	char	s[BUFFER_SIZE + 1];
	char	*ret;
	char	*stock;
	int		n;

	n = read(fd, s, BUFFER_SIZE);
	ret = ft_strdup(s);
	if (ret == 0)
		return (0);
	if (n != 0)
	{
		ft_bzero(s, BUFFER_SIZE);
		while (n != 0)
		{
			n = read(fd, s, BUFFER_SIZE);
			stock = ft_strjoin(ret, s);
			ft_bzero(s, BUFFER_SIZE);
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
	if (fd < 0 || read(fd,0,0) < 0)
		return (0);
	if (s == 0)
		s = ft_read(fd);
	if (s[i] != '\0')
	{
		line = ft_cut(s);
		while (s[i] != '\n' && s[i])
			i++;
		i++;
		s += i;
	return (line);
	}
	return (0);
}
