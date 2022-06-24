/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:01:50 by luserbu           #+#    #+#             */
/*   Updated: 2022/04/15 15:28:25 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!src && !dest)
		return (dest);
	i = 0;
	while (i < n)
	{
		*(unsigned char *)dest = *(unsigned char *)src;
		src++;
		dest++;
		i++;
	}
	while (i > 0)
	{
		dest--;
		src--;
		i--;
	}
	return (dest);
}
