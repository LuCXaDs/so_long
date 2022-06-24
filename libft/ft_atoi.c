/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:22:13 by luserbu           #+#    #+#             */
/*   Updated: 2022/04/01 18:15:17 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	final;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	neg = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if ((nptr[i] == '-' || nptr[i] == '+')
			&& (!(nptr[i + 1] >= '0' && nptr[i + 1] <= '9')))
			return (0);
		else if (nptr[i] == '-')
			neg *= -1;
		i++;
	}
	final = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		final = (final * 10) + (nptr[i] - 48);
		i++;
	}
	return (final * neg);
}
