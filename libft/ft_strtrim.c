/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:47:42 by luserbu           #+#    #+#             */
/*   Updated: 2022/04/15 14:41:26 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_check_letter(char s1, char *set);
char	*check_len(size_t i, size_t m);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	l;
	size_t	m;

	i = 0;
	if (!set || !s1)
		return (NULL);
	while (is_check_letter(s1[i], (char *)set) == 1)
		i++;
	m = ft_strlen((char *)s1);
	while (is_check_letter(s1[m - 1], (char *)set) == 1)
		m--;
	if (i > m)
		return (check_len(i, m));
	str = malloc(sizeof (char) * (m - i) + 1);
	if (!str)
		return (NULL);
	l = 0;
	while (i < m)
		str[l++] = s1[i++];
	str[l] = '\0';
	return (str);
}

int	is_check_letter(char s1, char *set)
{
	while (*set != '\0')
	{
		if (s1 == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*check_len(size_t i, size_t m)
{
	char	*str;

	if (i > m)
	{
		str = ft_calloc(sizeof (char), 1);
		return (str);
	}
	return (0);
}
