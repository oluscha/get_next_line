/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:23:46 by lschwart          #+#    #+#             */
/*   Updated: 2021/12/02 22:23:48 by lschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*buffer;
	int		length;
	int		i;

	length = ft_strlen(s1);
	i = 0;
	buffer = (char *) malloc(sizeof(char) * (length + 1));
	if (!buffer)
		return (NULL);
	else if (s1[i] == '\0')
		buffer[i] = '\0';
	else
	{
		while (s1[i] != '\0')
		{
			buffer[i] = s1[i];
			i++;
		}
		buffer[i] = '\0';
	}
	return (buffer);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	buffer = (char *) malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!buffer)
		return (0);
	if (buffer)
	{
		while (*s1 != '\0')
			buffer[i++] = *(s1++);
		while (*s2 != '\0')
			buffer[i++] = *(s2++);
		buffer[i] = '\0';
		return (buffer);
	}
	return (NULL);
}

char	*ft_strchr(const char *str, int ch)
{
	unsigned char	*buffer;
	int				i;

	i = 0;
	buffer = (unsigned char *)str;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == (char)ch)
			return ((char *)(buffer + i));
		i++;
	}
	if (buffer[i] == (char)ch)
		return ((char *)(buffer + i));
	return (0);
}

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
