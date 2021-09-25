/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 19:02:19 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/09/25 19:03:07 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ptr(t_print *tab)
{
	unsigned long	n;
	unsigned long	pow;
	char			c;

	tab->tlen += write(1, "0x", 2);
	n = va_arg(tab->args, unsigned long);
	pow = 1;
	while (n / pow / 16)
		pow *= 16;
	while (pow)
	{
		c = n / pow;
		if (c >= 0 && c <= 9)
			c += '0';
		else
			c += 'W';
		tab->tlen += write(1, &c, 1);
		n %= pow;
		pow /= 16;
	}
}
