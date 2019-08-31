/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 03:41:32 by clboutry          #+#    #+#             */
/*   Updated: 2019/08/31 04:15:11 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_print_unsigned_left(uintmax_t nbr, t_struct *info)
{
	int			nbrlen;

	nbrlen = ft_unsigned_nbr_len_base(nbr, 10);
	if (nbr == 0 && info->precision_find == 1 && info->precision == 0)
	{
		while (info->width)
		{
			write(1, " ", 1);
			info->width -= 1;
		}
		return ;
	}
	while (nbrlen++ < info->precision)
		write(1, "0", 1);
	ft_uitoa_base_printf(nbr, 10, 0);
	while (info->width >= nbrlen)
	{
		write(1, " ", 1);
		info->width -= 1;
	}
}

void			ft_padding(int nbrlen, t_struct *info)
{
	if (info->precision_find == 0 || info->precision < nbrlen)
		while (info->width-- > nbrlen)
		{
			if (info->zero == 1)
				write(1, "0", 1);
			else
				write(1, " ", 1);
		}
	else
	{
		if (info->plus == 1 || info->zero == 1)
			info->width--;
		if (info->precision > nbrlen)
			while (info->width-- > info->precision)
			{
				if (info->zero == 1)
					write(1, "0", 1);
				else
					write(1, " ", 1);
			}
	}
}

void			ft_print_unsigned_right(uintmax_t nbr, t_struct *info)
{
	int			nbrlen;

	nbrlen = ft_unsigned_nbr_len_base(nbr, 10);
	if (nbr == 0 && info->precision_find == 1 && info->precision == 0)
	{
		while (info->width)
		{
			write(1, " ", 1);
			info->width -= 1;
		}
		return ;
	}
	ft_padding(nbrlen, info);
	while (nbrlen++ < info->precision)
		write(1, "0", 1);
	ft_uitoa_base_printf(nbr, 10, 0);
}

void			ft_print_unsigned(const char *str, t_struct *info, va_list ap)
{
	uintmax_t	nbr;

	if (str[info->cmpt] == 'u')
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
		if (info->minus)
			ft_print_unsigned_left(nbr, info);
		else
			ft_print_unsigned_right(nbr, info);
	}
}
