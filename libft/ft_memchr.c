/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:42:04 by luserbu           #+#    #+#             */
/*   Updated: 2022/04/15 15:38:12 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*str;
	size_t			i;

	i = -1;
	str = (char *)s;
	if (n == 0)
		return (NULL);
	while (++i < n)
		if (str[i] == (char)c)
			return (str + i);
	return (NULL);
}
