/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:45:23 by luserbu           #+#    #+#             */
/*   Updated: 2022/04/15 15:29:46 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dt;
	char	*sc;

	if (!src && !dest)
		return (dest);
	i = -1;
	sc = (char *)src;
	dt = (char *)dest;
	if (dt < sc)
		while (++i < n)
			dt[i] = sc[i];
	else
		while (n--)
			dt[n] = sc[n];
	return (dest);
}
