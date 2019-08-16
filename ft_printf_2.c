/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 01:37:37 by clboutry          #+#    #+#             */
/*   Updated: 2019/08/14 08:34:28 by clboutry         ###   ########.fr       */
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
}

void			ft_aff(const char *str, t_struct *info, va_list ap)
{

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
			if (strchr("#-+ .*0123456789hlL"))
				ft_parsing(str, &info, ap);
			ft_aff(str, &info,  ap);
			ft_reset_struct(&info);
		}
		else if(info.phrase[info.cmpt] != '%')
			ft_putchar(str[info.cmpt]);
		info.cmpt++;
	}
	va_end(ap);
}

int				main(void)
{
	char 		*animal;
	char		*cri;

	animal	= "thon";
	cri 	= "blup blup";
	ft_printf_2("%s, disent les %9s. Ta mere sens le %6s. Donc ta mere dit %19s", cri, animal, animal, cri);
	return(0
}
