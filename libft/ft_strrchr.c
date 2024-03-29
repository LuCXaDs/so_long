/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:59:44 by luserbu           #+#    #+#             */
/*   Updated: 2022/08/31 14:29:55 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i])
		i++;
	if ((char)c == '\0')
		return (str + i);
	if (str[i] == (char)c)
		return (str + i);
	while (i >= 0)
	{
		if ((char)c == str[i])
			return (str + i);
		i--;
	}
	return (NULL);
}
