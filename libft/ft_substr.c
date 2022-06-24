/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:09:30 by luserbu           #+#    #+#             */
/*   Updated: 2022/06/07 15:42:21 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		str = malloc(sizeof(char) * 1);
		*str = '\0';
		return (str);
	}
	if (len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	str = (char *)malloc(sizeof (*s) * (len + 1));
	if (!str)
		return (NULL);
	str = last_tab(s, start, len, str);
	return (str);
}
