/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:07:29 by luserbu           #+#    #+#             */
/*   Updated: 2022/04/27 16:09:18 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_modulo(char c, va_list buffer);

int	ft_printf(const char *s, ...)
{
	int		i;
	int		cnt;
	va_list	buffer;

	i = 0;
	cnt = 0;
	va_start(buffer, s);
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '%')
		{
			cnt += is_modulo(s[i + 1], buffer);
			i += 2;
		}
		else
		{
			cnt += ft_putchar(s[i]);
			i++;
		}
	}
	va_end(buffer);
	return (cnt);
}

int	is_modulo(char c, va_list buffer)
{
	if (c == 'c')
		return (ft_putchar(va_arg(buffer, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(buffer, char *)));
	else if (c == 'd')
		return (ft_putnbr(va_arg(buffer, int)));
	else if (c == 'i')
		return (ft_putnbr(va_arg(buffer, int)));
	else if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(buffer, unsigned int)));
	else if (c == 'p')
		return (ft_putvoid(va_arg(buffer, unsigned long long)));
	else if (c == 'x')
		return (ft_puthex_min(va_arg(buffer, unsigned int)));
	else if (c == 'X')
		return (ft_puthex_maj(va_arg(buffer, unsigned int)));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}
