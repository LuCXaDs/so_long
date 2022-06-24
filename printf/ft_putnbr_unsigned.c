/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:53:08 by luserbu           #+#    #+#             */
/*   Updated: 2022/04/18 15:06:19 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int	cnt;

	cnt = 0;
	if (n >= 10)
	{
		cnt += ft_putnbr_unsigned(n / 10);
		cnt += ft_putchar((n % 10) + 48);
	}
	else
		cnt += ft_putchar((n % 10) + 48);
	return (cnt);
}
