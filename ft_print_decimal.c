/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 04:45:04 by clboutry          #+#    #+#             */
/*   Updated: 2019/08/31 04:21:41 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_right2(intmax_t nbr, int neg, t_struct *info)
{
	if (nbr == 0 && info->precision_find == 1 && info->precision == 0)
	{
		if (info->plus == 1 && info->width)
			info->width -= 1;
		while (info->width)
		{
			write(1, " ", 1);
			info->width -= 1;
		}
		if (info->plus == 1)
			write(1, "+", 1);
		return (1);
	}
	if (info->space == 1 && neg == 0 && info->width == 0)
		write(1, " ", 1);
	if (info->plus == 1 && info->zero == 1 && neg == 0)
		write(1, "+", 1);
	if (neg == 1 && info->zero == 1)
		write(1, "-", 1);
	return (0);
}

void		ft_print_right(intmax_t nbr, t_struct *info)
{
	int nbrlen;
	int neg;

	nbrlen = ft_nbr_len_base(nbr, 10);
	neg = (nbr < 0) ? 1 : 0;
	nbr = (nbr < 0) ? -nbr : nbr;
	if (ft_print_right2(nbr, neg, info))
		return ;
	if (info->plus == 1 && neg == 0 && info->width && info->precision_find == 0)
		nbrlen++;
	ft_padding_right(nbrlen, neg, info);
	if (info->zero == 0 && info->plus == 1 && neg == 0)
		write(1, "+", 1);
	else if (info->zero == 0 && neg == 1)
	{
		write(1, "-", 1);
		nbrlen--;
	}
	info->precision = (info->width > info->precision)
		? info->width : info->precision;
	while (nbrlen++ < info->precision)
		write(1, "0", 1);
	ft_itoa_base_printf(nbr, 10);
}

int			ft_print_left2(intmax_t nbr, int neg, t_struct *info)
{
	if (nbr == 0 && info->precision_find == 1 && info->precision == 0)
	{
		if (info->plus == 1 && info->width)
		{
			info->width--;
			write(1, "+", 1);
		}
		while (info->width != 0)
		{
			write(1, " ", 1);
			info->width--;
		}
		return (1);
	}
	if (info->space == 1 && neg == 0)
	{
		write(1, " ", 1);
		info->width--;
	}
	return (0);
}

void		ft_print_left(intmax_t nbr, t_struct *info)
{
	int nbrlen;
	int neg;

	nbrlen = ft_nbr_len_base(nbr, 10);
	neg = (nbr < 0) ? 1 : 0;
	nbr = (nbr < 0) ? nbr *= -1 : nbr;
	if (ft_print_left2(nbr, neg, info) == 1)
		return ;
	if (info->plus == 1 && neg == 0)
	{
		write(1, "+", 1);
		info->precision++;
		nbrlen++;
	}
	if (neg == 1)
	{
		write(1, "-", 1);
		nbrlen--;
		info->width--;
	}
	while (nbrlen++ < info->precision)
		write(1, "0", 1);
	ft_itoa_base_printf(nbr, 10);
	ft_padding_left(nbrlen, info);
}

void		ft_print_decimal(const char *str, t_struct *info, va_list ap)
{
	intmax_t nbr;

	if (str[info->cmpt] == 'd' || str[info->cmpt] == 'i')
	{
		if (info->length == 0)
			nbr = va_arg(ap, int);
		else if (info->length == 2)
			nbr = (signed char)va_arg(ap, int);
		else if (info->length == 1)
			nbr = (short)va_arg(ap, int);
		else if (info->length == 3)
			nbr = va_arg(ap, long);
		else if (info->length == 4)
			nbr = va_arg(ap, long long);
		if (info->minus == 1)
			ft_print_left(nbr, info);
		else
			ft_print_right(nbr, info);
	}
}
