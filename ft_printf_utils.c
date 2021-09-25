/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 10:51:57 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/09/25 10:54:26 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(t_print *tab)
{
	char	c;
	c = va_arg(tab->args, int);
	ft_update_tab(tab, 1); // calculate special cases and len
	if (tab->wd && !tab->dash) // if widht and not - flag
		ft_right_cs(tab, 0); // handle right aligment
	tab->tlen += write(1, &c, 1);
	if (tab->wd && tab->dash)
		ft_left_cs(tab, 0); // handle left aligment
}
