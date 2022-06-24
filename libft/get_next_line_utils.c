/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 22:47:34 by luserbu           #+#    #+#             */
/*   Updated: 2022/06/07 16:20:18 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*last_tab(const char *s, unsigned int start, size_t len, char *str);

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s || !len)
		return (NULL);
	if (start >= ft_strlen((char *)s))
	{
		str = malloc(sizeof(char) * 1);
		*str = '\0';
		return (str);
	}
	if (len >= ft_strlen((char *)s))
		len = ft_strlen((char *)s) - start;
	str = (char *)malloc(sizeof (*s) * (len + 1));
	if (!str)
		return (NULL);
	str = last_tab(s, start, len, str);
	return (str);
}

char	*last_tab(const char *s, unsigned int start, size_t len, char *str)
{
	size_t	i;
	size_t	si;

	si = 0;
	i = 0;
	while (s[i])
	{
		if (i >= (size_t)start && si < len)
		{
			str[si] = s[i];
			si++;
		}
		i++;
	}
	str[si] = '\0';
	return (str);
}

size_t	ft_strlcat_gnl(char *dst, const char *src, size_t size);
size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t size);

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen((char *)s1);
	j = ft_strlen((char *)s2) + 1;
	str = malloc(sizeof(char) * (i + j));
	if (!str)
		return (NULL);
	ft_strlcpy_gnl(str, s1, (i + j));
	ft_strlcat_gnl(str, s2, (i + j));
	free((char *)s1);
	return (str);
}

size_t	ft_strlcat_gnl(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	y;

	i = ft_strlen(dst);
	y = ft_strlen((char *)src);
	if (size == 0 || i > size)
		return (size + y);
	if (!*src)
		return (i);
	j = 0;
	while (src[j] && (i + j < size - 1))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + y);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
