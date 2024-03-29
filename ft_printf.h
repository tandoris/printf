/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 02:22:36 by clboutry          #+#    #+#             */
/*   Updated: 2019/08/31 22:55:34 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef	struct	s_struct
{
	int			cmpt;
/*		flags */
	int			hash;
	int			zero;
	int			minus;
	int			plus;
	int			space;
/*	 Minimum field width */
	int			width;
/*	precision field */
	int			precision;
	int			precision_find;
/*	longueur field
	 1 = h | 2 = hh | 3 = l | 4 = ll | 5 = L */
	int			length;
/*	autres */
	int			found;
	char		*atoi;
}				t_struct;

void			ft_printf_2(const char *str, ...);
void			ft_parsing(const char *str, t_struct *info, va_list ap);
void			ft_print_decimal(const char *str, t_struct *info, va_list ap);
int				ft_nbr_len_base(intmax_t nbr, int base);
int				ft_itoa_base_printf(intmax_t nbr, int base);
void			ft_padding_left(int nbrlen, t_struct *info);
void			ft_padding_right(int nbrlen, int neg, t_struct *info);
void			ft_print_char(const char *str, t_struct *info, va_list ap);
void			ft_print_string(const char *str, t_struct *info, va_list ap);
void			ft_print_pointer(const char *str, t_struct *info, va_list ap);
int				ft_uitoa_base_printf(uintmax_t nbr, int base, char x);
int				ft_unsigned_nbr_len_base(uintmax_t nbr, int base);
void			ft_print_percent(const char *str, t_struct *info);
void			ft_print_hex(const char *str, t_struct *info, va_list ap);
void			ft_print_oct(const char *str, t_struct *info, va_list ap);
void			ft_print_unsigned(const char *str, t_struct *info, va_list ap);
#endif
