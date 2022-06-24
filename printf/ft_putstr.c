/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 09:35:22 by luserbu           #+#    #+#             */
/*   Updated: 2022/04/27 16:14:18 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	cnt;

	cnt = 0;
	if (s == NULL)
		return (cnt += ft_putstr("(null)"));
	if (s)
		while (*s != '\0')
			cnt += write(1, s++, 1);
	return (cnt);
}
