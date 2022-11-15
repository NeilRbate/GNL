/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 07:18:59 by jbarbate          #+#    #+#             */
/*   Updated: 2022/11/15 09:53:14 by jbarbate         ###   ########.fr       */
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
	int		n;

	n = read(fd, s, BUFFER_SIZE);
	if (n < 0)
		return (0);
	ret = ft_strdup(s);
	while (n)
	{
		n = read(fd, s, BUFFER_SIZE);
		s[n] = '\0';
		ret = ft_strjoin(ret, s);
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*line;
	int			i;

	i = 0;
	if (fd < 0)
		return (0);
	if (s == 0)
	{
		s = ft_read(fd);
		if (s <= 0)
			return (0);
	}
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
