/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 02:22:36 by clboutry          #+#    #+#             */
/*   Updated: 2019/08/13 09:43:52 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "../ft_printf/libft/libft.h"

/* flag : 0 | 1 | 2 | 3 | 4
 * 		  #   0   -   +  esp */



typedef	struct s_struct
{
	int 			cmpt;
	const char		*phrase;
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
	int				lenght;
	//autres
	char			*atoi;
}				t_struct;

void			ft_printf_2(const char *str, ...);
void			ft_parsing(const char *str, t_struct *info, va_list ap);

#endif
