/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 12:17:06 by luserbu           #+#    #+#             */
/*   Updated: 2022/04/21 17:23:33 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_min(unsigned int nb)
{
	int	size;

	size = 0;
	if (nb >= 16)
	{
		size += ft_puthex_min(nb / 16);
		size += ft_puthex_min(nb % 16);
	}
	else if (nb >= 10)
		size += ft_putchar(nb + 'a' - 10);
	else if (nb < 10)
		size += ft_putchar(nb + 48);
	return (size);
}
