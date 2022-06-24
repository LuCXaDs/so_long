/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:53:08 by luserbu           #+#    #+#             */
/*   Updated: 2022/04/27 16:11:04 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int				cnt;
	unsigned int	nbr;

	cnt = 0;
	nbr = n;
	if (n < 0)
	{
		cnt += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		cnt += ft_putnbr(nbr / 10);
		cnt += ft_putchar((nbr % 10) + 48);
	}
	else
		cnt += ft_putchar(nbr + 48);
	return (cnt);
}
