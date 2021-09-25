/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 19:01:47 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/09/25 19:02:11 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_uint(t_print *tab)
{
	unsigned int		n;
	unsigned int		pow_ten;
	char				c;

	n = va_arg(tab->args, unsigned int);
	pow_ten = 1;
	while (n / pow_ten / 10)
		pow_ten *= 10;
	while (pow_ten)
	{
		c = n / pow_ten + '0';
		tab->tlen += write(1, &c, 1);
		n %= pow_ten;
		pow_ten /= 10;
	}
}
