/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 07:18:59 by jbarbate          #+#    #+#             */
/*   Updated: 2022/11/15 08:43:46 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *s)
{
	int		n;
	char	*stock;

	s = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (s == 0)
		return (0);
	n = read(fd, s, BUFFER_SIZE);
	if (n == -1)
		return (0);
	s[BUFFER_SIZE] = '\0';
	if (n == 0)
		return (s);
	while (n != 0)
	{
		stock = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
		n = read(fd, stock, BUFFER_SIZE);
		stock[BUFFER_SIZE] = '\0';
		s = ft_strjoin(s, stock);
	}
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*stock;
	char		*f;
	int			i;

	i = 0;
	stock = 0;
	if (fd <= 0)
		return (0);
	if (s == 0)
	{
		s = ft_read(fd, s);
		if (s == 0)
			return (0);
	}
	if (s[i] != '\0')
	{
		while (s[i] != '\n' && s[i])
			i++;
		stock = malloc(sizeof(char) * i + 1);
		if (i > 0)
			stock[i--] = '\0';
		while (i >= 0)
		{
			stock[i] = s[i];
			i--;
		}
		s = ft_strdup((s + (ft_strlen(stock) + 1)));
		return (stock);
	}
	return (stock);
}
