/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 10:19:49 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/09/25 10:51:34 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print *ft_initialise_tab(t_print *tab)
{
	tab = {0, 0, 0, 0, 0, 0, 0 ,0, 0, 0};
	return (tab);
}

ft_eval_format(t_print *tab, const char *format, int i)
{
	if (format[i] == 'c')
		ft_print_char(tab);
	if (format[i] == 'd' || format[i] == 'i')
		ft_print_int(tab);
	// etc
}

ft_eval_flags(t_print *tab, const char *format, int i)
{
	while (!ft_strrchr("udcsupxX%", format[i]))
	{
		if (format[i] == '.' && ++i)
			tab->pnt = 1;
		if (format[i] == '-' && ++i)
			tab->dash = 1;
		// etc
	}
	// TODO: call funcstion do detect type to print
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		ret;
	t_print *tab;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_initialise_tab(tab);
	va_start(tab->args, format);
	ret = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
			i = ft_eval_format(tab, format, i + 1);
		else
			ret += write(1, &format[i], 1);
	}
	va_end(tab->args);
	ret += tab->tlen;
	free(tab);
	return (ret);
}
