/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 10:24:26 by dpoveda-          #+#    #+#             */
/*   Updated: 2021/09/25 20:41:01 by dpoveda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_print
{
	va_list	args;
	int		wd;
	int		dot;
	int		dash;
	int		zero;
	int		sharp;
	int		sp;
	int		plus;
	int		tlen;
	int		sign;
	int		is_zero;
	int		perc;
}	t_print;

int		ft_printf(const char *format, ...);
t_print	*ft_initialise_tab(t_print *tab);
t_print	*ft_clear_flags_tab(t_print *tab);
void	ft_print_char(t_print *tab);
void	ft_print_str(t_print *tab);
void	ft_print_int(t_print *tab);
void	ft_print_uint(t_print *tab);
void	ft_print_ptr(t_print *tab);
void	ft_print_hex(t_print *tab, char flag);

#endif
