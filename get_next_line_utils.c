/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbate <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 07:21:05 by jbarbate          #+#    #+#             */
/*   Updated: 2022/11/16 08:55:02 by jbarbate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*stock;

	i = 0;
	stock = (unsigned char *)s;
	while (i < n)
	{
		*stock = 0;
		stock++;
		i++;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (dstsize > 0)
	{
		while (src[i])
		{
			if (dstsize > 0 && i < (dstsize - 1))
			{
				dst[j] = src[j];
				j++;
			}
			i++;
		}
		dst[j] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s1)
{
	char	*ret;

	ret = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!ret)
		return (0);
	ft_strlcpy(ret, s1, ft_strlen(s1) + 1);
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len_t;
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	len_t = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc(sizeof(char) * len_t + 1);
	if (ret == 0)
		return (0);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j])
		ret[i++] = s2[j++];
	ret[i] = '\0';
	return (free(s1), ret);
}
