/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 10:24:26 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/09/25 10:45:38 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct s_print
{
	va_list args;
	int wd;
	int prc;
	int zero;
	int pnt;
	int dash;
	int tlen;
	int sign;
	int is_zero;
	int perc;
	int sp;
}	t_print

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);

#endif

