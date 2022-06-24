/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 12:17:06 by luserbu           #+#    #+#             */
/*   Updated: 2022/04/18 13:02:07 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_maj(unsigned int nb)
{
	int	size;

	size = 0;
	if (nb >= 16)
	{
		size += ft_puthex_maj(nb / 16);
		size += ft_puthex_maj(nb % 16);
	}
	else if (nb >= 10)
		size += ft_putchar(nb + 'A' - 10);
	else if (nb < 10)
		size += ft_putchar(nb + 48);
	return (size);
}
