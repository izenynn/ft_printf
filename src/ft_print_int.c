/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 19:00:51 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/09/25 22:48:38 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_handle_sign(t_print *tab, short sign, int print_len)
{
	print_len--;
	if (sign)
		tab->tlen += write (1, "-", 1);
	else if (tab->plus)
		tab->tlen += write(1, "+", 1);
	else if (tab->sp)
		tab->tlen += write(1, " ", 1);
	else
		print_len++;
	return (print_len);
}

static int	ft_get_print_len(t_print *tab, short sign, int len)
{
	int	print_len;

	if (tab->dot)
	{
		if (tab->dot > len)
			print_len = tab->dot + sign - 1;
		else
			print_len = len;
	}
	else if (tab->zero)
		print_len = tab->wd;
	else
	{
		print_len = len;
		if (sign)
			print_len++;
	}
	return (print_len);
}

static void	ft_handle_left_align(t_print *tab, int print_len)
{
	tab->wd -= print_len;
	while (tab->wd-- > 0)
		tab->tlen += write(1, " ", 1);
}

static void ft_print_sign_and_zeros(t_print *tab, int n, int sign, int print_len)
{
	print_len -= ft_intlen(n);
	print_len = ft_handle_sign(tab, sign, print_len);
	while (print_len-- > 0)
		tab->tlen += write(1, "0", 1);
}

void	ft_print_int(t_print *tab)
{
	int				n;
	short			sign;
	unsigned int	pow_ten;
	char			c;
	int				print_len;

	n = va_arg(tab->args, int);
	pow_ten = 1;
	sign = 0;
	if (n < 0 && ++sign)
		n = -n;
	print_len = ft_get_print_len(tab, sign, ft_intlen(n));
	ft_handle_left_align(tab, print_len);
	ft_print_sign_and_zeros(tab, n, sign, print_len);
	while (n / pow_ten / 10)
		pow_ten *= 10;
	while (pow_ten && print_len--)
	{
		c = n / pow_ten + '0';
		tab->tlen += write(1, &c, 1);
		n %= pow_ten;
		pow_ten /= 10;
	}
}
