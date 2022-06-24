/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:04:57 by luserbu           #+#    #+#             */
/*   Updated: 2022/04/15 15:05:29 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	m;

	i = 0;
	if (*little == '\0' || little == NULL)
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (little[0] == big[i])
		{
			m = 0;
			while (little[m] == big[i + m] && i + m < len)
			{
				m++;
				if (little[m] == '\0')
					return ((char *)big + i);
			}
		}
		i++;
	}
	return (NULL);
}
