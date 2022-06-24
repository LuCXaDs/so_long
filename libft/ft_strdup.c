/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:58:07 by luserbu           #+#    #+#             */
/*   Updated: 2022/04/15 14:58:31 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;
	char	*st;

	st = (char *)s;
	i = 0;
	while (st[i])
		i++;
	str = malloc(sizeof (char) * (i + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (st[++i])
		str[i] = st[i];
	str[i] = '\0';
	return (str);
}
