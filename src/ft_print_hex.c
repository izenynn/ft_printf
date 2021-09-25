/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 19:03:15 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/09/25 19:44:42 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_handle_sharp(t_print *tab, char flag, unsigned int n)
{
	if (tab->sharp && n)
	{
		if (flag == 'x')
			tab->tlen += write(1, "0x", 2);
		else
			tab->tlen += write(1, "0X", 2);
	}
}

void	ft_print_hex(t_print *tab, char flag)
{
	unsigned int	n;
	unsigned int	pow;
	char			c;

	n = va_arg(tab->args, unsigned long);
	ft_handle_sharp(tab, flag, n);
	pow = 1;
	while (n / pow / 16)
		pow *= 16;
	while (pow)
	{
		c = n / pow + '0';
		if (!(c >= '0' && c <= '9'))
		{
			c += 7;
			if (flag == 'x')
				c += 32;
		}
		tab->tlen += write(1, &c, 1);
		n %= pow;
		pow /= 16;
	}
}
