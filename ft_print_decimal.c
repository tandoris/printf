/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 04:45:04 by clboutry          #+#    #+#             */
/*   Updated: 2019/08/23 09:02:41 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_right2(intmax_t nbr, int neg, t_struct *info, int nbrlen)
{
	if (neg == 1 || info->plus == 1)
		info->width--;
	if (info->space == 1 && neg != 1)
	{
		write(1, " ", 1);
		info->width--;
	}
	info->width = (nbrlen >= info->precision) ? info->width - nbrlen : info->width - info->precision;
	info->precision = (nbr != 0) ? info->precision - nbrlen : info->precision;
	while ((info->precision_find == 1 && info->width > 0) || (info->zero == 0 && info->width > 0))
	{
		write(1, " ", 1);
		info->width -= 1;
	}
	while (info->width-- > 0 && info->zero == 1)
	{
		if (neg == 1 || (info->plus && neg == 1))
			write(1, "-", 1);
		if (info->plus && neg == 0)
			write(1, "+", 1);
		neg = 0;
		info->plus = 0;
		write(1, "0", 1);
	}
	return (neg);
}

void		ft_print_right(intmax_t nbr, t_struct *info)
{
	int nbrlen;
	int	neg;
	int	z;

	neg = (nbr < 0) ? 1 : 0;
	nbr = (nbr < 0) ? -nbr : nbr;
	z = (nbr == 0) ? 1 : 0;
	nbrlen = ft_nbr_len_base(nbr, 10);
	neg = ft_print_right2(nbr, neg, info, nbrlen);
	if (nbr == 0 && info->precision == 0)
		write(1, " ", 1);
	if ((info->plus == 1 && neg == 1) || neg == 1)
		write(1, "-",1);
	if (info->plus == 1 && neg == 0)
		write(1, "+", 1);
	while (info->precision > z)
	{
		write(1, "0", 1);
		info->precision -= 1;
	}
	if (nbr != 0 || info->precision != 0)
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
	if (info->plus ==  1 && neg == 0)
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

// 1 = h | 2 = hh | 3 = l | 4 = ll | 5 = L
