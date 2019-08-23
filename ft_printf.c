/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 01:37:37 by clboutry          #+#    #+#             */
/*   Updated: 2019/08/23 09:02:47 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_reset_struct(t_struct *info)
{
	info->hash = 0;
	info->zero = 0;
	info->minus = 0;
	info->plus = 0;
	info->space = 0;
	info->width = 0;
	info->precision = 0;
	info->precision_find = 0;
	info->length = 0;
	info->found = 0;
}

void			ft_aff(const char *str, t_struct *info, va_list ap)
{
	if (str[info->cmpt] == 'd' || str[info->cmpt] == 'i')
		ft_print_decimal(str, info, ap);
	/*else if (str[info->cmpt] == 'o')
		ft_print_octal(str[info->cmpt], info, ap);
	else if (str[info->cmpt] == 'u')
		ft_print_unsigned(str[info->cmpt], info, ap);
	else if (str[info->cmpt] == 'x' || str[info->cmpt] == 'X')
		ft_print_hex(str[info->cmpt], info, ap);
	else if (str[info->cmpt] == 'p')
		ft_print_pointer(str[info->cmpt], info, ap);
	else if (str[info->cmpt] == 'c')
		ft_print_char(str[info->cmpt], info, ap);
	else if (str[info->cmpt] == 's')
		ft_print_string(str[info->cmpt], info, ap);
	else if (str[info->cmpt] == '%')
		ft_print_percent(str[info->cmpt], info);*/
}

void			ft_printf_2(const char *str, ...)
{
	va_list		ap;
	t_struct	info;

	ft_reset_struct(&info);
	info.cmpt = 0;
	va_start(ap, str);
	while (str[info.cmpt])
	{
		if(str[info.cmpt] == '%')
		{
			info.cmpt++;
			ft_parsing(str, &info, ap);
			  if (info.found == 1)
		  		ft_aff(str, &info,  ap);
		//	else
		//		ft_aff_error_carac()
			ft_reset_struct(&info);
		}
		else if(str[info.cmpt] != '%')
			ft_putchar(str[info.cmpt]);
		info.cmpt++;
	}
	va_end(ap);
}

int				main(int ac, char **av)
{
	char 		*animal;
	char		*cri;
	int 		a;
	
	(void)ac;
	a = -15;
	animal	= "thon";
	cri 	= "blup blup";
	ft_printf_2(av[1], a);
	write(1, "\n", 1);
	printf(av[1], a);
	return(0);
}
