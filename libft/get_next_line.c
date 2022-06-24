/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:40:14 by luserbu           #+#    #+#             */
/*   Updated: 2022/06/07 16:19:42 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_find_backslash_n(int fd, char *str, char *buff);
int		is_backslash_n(char *buff);
int		ft_strlen_n(char *str);

char	*get_next_line(int fd)
{
	char		*buff;
	char		*str;
	char		*line;
	static char	*save;

	buff = malloc(sizeof (char) * 2);
	if (!buff || fd < 0 || read(fd, buff, 0) == -1)
		return (free(buff), NULL);
	str = malloc(1);
	*str = 0;
	if (save)
	{
		str = ft_strjoin_gnl(str, save);
		free(save);
	}
	str = ft_find_backslash_n(fd, str, buff);
	line = ft_substr_gnl(str, 0, ft_strlen_n(str));
	save = ft_substr_gnl(str, ft_strlen_n(str), (int)ft_strlen(str) - ft_strlen_n(str));
	return (free(buff), free(str), line);
}

char	*ft_find_backslash_n(int fd, char *str, char *buff)
{
	int	len;

	len = 1;
	while (is_backslash_n(str) == 0 && len)
	{
		len = read(fd, buff, 1);
		buff[len] = '\0';
		str = ft_strjoin_gnl(str, buff);
	}
	return (str);
}

int	is_backslash_n(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen_n(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}
