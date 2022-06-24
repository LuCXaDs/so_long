/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 20:29:21 by luserbu           #+#    #+#             */
/*   Updated: 2022/04/04 14:57:54 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s_1;
	unsigned char	*s_2;

	s_1 = (unsigned char *)s1;
	s_2 = (unsigned char *)s2;
	i = -1;
	if (n <= 0)
		return (0);
	while (++i < (n))
		if (s_1[i] - s_2[i] != 0)
			return ((unsigned char)s_1[i] - (unsigned char)s_2[i]);
	return (0);
}
