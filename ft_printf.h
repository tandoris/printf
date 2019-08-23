/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 02:22:36 by clboutry          #+#    #+#             */
/*   Updated: 2019/08/23 09:02:43 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef	struct s_struct
{
	int 			cmpt;
	char 			**arg;
	char			*type;
	//flags
	int				hash;
	int				zero;
	int				minus;
	int				plus;
	int				space;
	// Minimum field width
	int				width;
	//precision field
	int				precision;
	int				precision_find;
	//longueur field
	// 1 = h | 2 = hh | 3 = l | 4 = ll | 5 = L
	int				length;
	//autres
	int				found;
	char			*atoi;
}				t_struct;

void			ft_printf_2(const char *str, ...);
void			ft_parsing(const char *str, t_struct *info, va_list ap);
void			ft_print_decimal(const char *str, t_struct *info, va_list ap);
int         	ft_nbr_len_base(intmax_t value, int base);
int         	ft_itoa_base_printf(intmax_t nbr, int base);
void    		ft_padding_left(int nbrlen, t_struct *inf0);
void    		ft_padding_right(int nbrlen, t_struct *info);
#endif
