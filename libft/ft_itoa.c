/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:04:27 by luserbu           #+#    #+#             */
/*   Updated: 2022/04/15 15:23:53 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_int_min(char *str);
int		ft_nbrlen(long int nbr);

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		len;

	len = ft_nbrlen((long int)n);
	str = ft_calloc(sizeof (char), (len + 1));
	if (!str)
		return (NULL);
	if (n == -2147483648)
		return (ft_int_min(str));
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	i = len - 1;
	while (n > 0)
	{
		str[i] = (n % 10) + 48;
		n /= 10;
		i--;
	}
	return (str);
}

int	ft_nbrlen(long int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		len++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_int_min(char *str)
{
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}
