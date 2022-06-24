/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:05:26 by luserbu           #+#    #+#             */
/*   Updated: 2022/04/15 15:32:49 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stddef.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2) + 1;
	str = malloc(sizeof(char) * (i + j));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, (i + j));
	ft_strlcat(str, s2, (i + j));
	return (str);
}
