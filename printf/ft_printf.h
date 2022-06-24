/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:12:29 by luserbu           #+#    #+#             */
/*   Updated: 2022/04/27 16:15:59 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>

int		ft_printf(const char *s, ...);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_puthex_min(unsigned int nb);
int		ft_puthex_maj(unsigned int nb);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_putvoid(unsigned long long ptr);
#endif
