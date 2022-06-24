/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:18:38 by luserbu           #+#    #+#             */
/*   Updated: 2022/04/21 19:25:18 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_p(unsigned long long nb);

int	ft_putvoid(unsigned long long ptr)
{
	int	cnt;

	cnt = 0;
	if (!ptr)
	{
		cnt += ft_putstr("(nil)");
		return (cnt);
	}
	cnt += ft_putstr("0x");
	cnt += ft_puthex_p(ptr);
	return (cnt);
}

int	ft_puthex_p(unsigned long long nb)
{
	int	size;

	size = 0;
	if (nb >= 16)
	{
		size += ft_puthex_p(nb / 16);
		size += ft_puthex_p(nb % 16);
	}
	else if (nb >= 10)
		size += ft_putchar(nb + 'a' - 10);
	else if (nb < 10)
		size += ft_putchar(nb + 48);
	return (size);
}
