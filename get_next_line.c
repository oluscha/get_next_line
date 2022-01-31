/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:23:34 by lschwart          #+#    #+#             */
/*   Updated: 2021/12/02 22:23:39 by lschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check(int fd)
{
	char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || fd > 10240 || (read(fd, buffer, 0) < 0) || BUFFER_SIZE <= 0)
		return (0);
	return (1);
}

void	ft_free(char *help)
{
	if (help)
		free (help);
	help = NULL;
}

char	*check_ostatok(char *ostatok, char **result)
{
	char	*p_n;
	char	*help;

	p_n = NULL;
	if (ostatok)
	{
		if ((ft_strchr(ostatok, '\n')))
		{
			help = ft_strdup(ostatok);
			p_n = ft_strchr(help, '\n');
			ostatok = ft_strcpy(ostatok, ++p_n);
			*p_n = '\0';
			*result = ft_strdup(help);
			ft_free (help);
		}
		else
		{
			if (*ostatok == '\0')
				result = NULL;
			else
				*result = ft_strdup(ostatok);
		}
	}
	return (p_n);
}

char	*ft_strjoin_and_free(char *result, char *buffer, char **ostatok,
		int byte_was_read)
{
	char	*help;
	char	*p_n;

	help = NULL;
	if (ft_strchr(buffer, '\n'))
	{
		p_n = ft_strchr(buffer, '\n');
		*ostatok = ft_strdup(++p_n);
		*p_n = '\0';
	}
	help = result;
	result = ft_strjoin(result, buffer);
	ft_free (help);
	if (!byte_was_read && !(ft_strlen(result)))
	{
		free(result);
		return (NULL);
	}
	return (result);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	int			byte_was_read;
	char		*p_n;
	static char	*ostatok;
	char		*result;

	result = NULL;
	if (!ft_check(fd))
		return (0);
	p_n = check_ostatok(ostatok, &result);
	byte_was_read = 1;
	while (!p_n && byte_was_read)
	{
		free (ostatok);
		ostatok = NULL;
		byte_was_read = read(fd, buffer, BUFFER_SIZE);
		buffer[byte_was_read] = '\0';
		p_n = ft_strchr(buffer, '\n');
		result = ft_strjoin_and_free(result, buffer, &ostatok, byte_was_read);
	}
	return (result);
}
