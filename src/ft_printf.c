/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 10:19:49 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/09/28 12:23:20 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_eval_format(t_print *tab, const char *format, int i)
{
	if (format[i] == 'c')
		ft_print_char(tab);
	else if (format[i] == 's')
		ft_print_str(tab);
	else if (format[i] == 'p')
		ft_print_ptr(tab);
	else if (format[i] == 'd' || format[i] == 'i')
		ft_print_int(tab);
	else if (format[i] == 'u')
		ft_print_uint(tab);
	else if (format[i] == 'x' || format[i] == 'X')
		ft_print_hex(tab, format[i]);
	else if (format[i] == '%')
		tab->tlen += write(1, "%", 1);
	ft_clear_flags_tab(tab);
	return (i);
}

static int	ft_eval_flags(t_print *tab, const char *format, int i)
{
	while (!ft_strchr("cspdiuxX%", format[i]))
	{
		if (format[i] == '.' && ++i)
		{
			while (format[i] >= '0' && format[i] <= '9')
				tab->dot = tab->dot * 10 + format[i++] - '0';
			tab->dot++;
		}
		if (format[i] == '-' && ++i)
			tab->dash = 1;
		if (format[i] == '0' && ++i)
			tab->zero = 1;
		if (format[i] == '#' && ++i)
			tab->sharp = 1;
		if (format[i] == ' ' && ++i)
			tab->sp = 1;
		if (format[i] == '+' && ++i)
			tab->plus = 1;
		if (format[i] >= '1' && format[i] <= '9')
			while (format[i] >= '0' && format[i] <= '9')
				tab->wd = tab->wd * 10 + format[i++] - '0';
	}
	return (ft_eval_format(tab, format, i));
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		ret;
	t_print	*tab;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_initialise_tab(tab);
	va_start(tab->args, format);
	ret = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1])
			i = ft_eval_flags(tab, format, i + 1);
		else if (format[i] != '%')
			ret += write(1, &format[i], 1);
	}
	va_end(tab->args);
	ret += tab->tlen;
	free(tab);
	return (ret);
}
