/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_oct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 03:53:23 by clboutry          #+#    #+#             */
/*   Updated: 2019/08/30 05:13:51 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_print_oct_left(uintmax_t nbr, t_struct *info)
{
	int			nbrlen;

	nbrlen = ft_unsigned_nbr_len_base(nbr, 8);
	if (nbr == 0 && info->precision_find == 1 && info->precision == 0)
	{
		while (info->width > 0)
		{
//			write (1, " ", 1);
			info->width -= 1;
		}
		return ;
	}
	if (info->hash == 1 && nbr != 0)
	{
		info->width -= 1;
		write (1, "0", 1);
	}
	while (nbrlen++ < info->precision)
		write(1, "0", 1);
	ft_uitoa_base_printf(nbr, 8, 0);
	while (info->width-- >= nbrlen)
		write(1, " ", 1);
}

void			ft_padding_oct(int nbrlen, t_struct *info)
{
	if (info->precision_find == 0)
		while (info->width-- > nbrlen)
		{
			if (info->zero == 1)
				write(1, "0", 1);
			else
				write(1, " ", 1);
		}
	else
	{
		while(nbrlen < info->precision)
			nbrlen++;
		if (info->zero == 1)
			info->width--;
		while (info->width-- > nbrlen)
		{
			if (info->zero == 1)
				write(1, "0", 1);
			else
				write(1, " ", 1);
		}
	}
}

void			ft_print_oct_right(uintmax_t nbr, t_struct *info)
{
	int			nbrlen;
	int			h;

	nbrlen = ft_unsigned_nbr_len_base(nbr, 8);
	h = (info->precision > nbrlen) ?  1 : 0;
	if (nbr == 0 && info->precision_find == 1 && info->precision == 0)
	{
		while (info->width)
		{
			write(1, " ", 1);
			info->width -= 1;
		}
		return ;
	}
	if (info->hash == 1 && nbr != 0 && h == 0)
			info->width -= 1;
	ft_padding_oct(nbrlen, info);
	if (info->hash == 1 && h == 0)
		write (1, "0", 1);
	while (nbrlen++ < info->precision)
		write(1, "0", 1);
	ft_uitoa_base_printf( nbr, 8, 0);
}

void                    ft_print_oct(const char *str, t_struct *info, va_list ap)
{
	uintmax_t       nbr;

	if (str[info->cmpt] == 'o' )
	{
		if (info->length == 0)
			nbr = va_arg(ap, unsigned int);
		else if (info->length == 2)
			nbr = (unsigned char)va_arg(ap, unsigned int);
		else if (info->length == 1)
			nbr = (unsigned short)va_arg(ap, unsigned int);
		else if (info->length == 3)
			nbr = va_arg(ap, unsigned long);
		else if (info->length == 4)
			nbr = va_arg(ap, unsigned long long);
		if (info->minus == 1)
			ft_print_oct_left(nbr, info);
		else
			ft_print_oct_right(nbr, info);
	}
}
