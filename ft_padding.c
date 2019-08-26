/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 01:40:47 by clboutry          #+#    #+#             */
/*   Updated: 2019/08/26 19:55:05 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_padding_left(int nbrlen, t_struct *info)
{
	while (info->width >= nbrlen)
	{
		write(1, " ", 1);
		info->width--;
	}
}

void	ft_padding_right(int nbrlen, int neg, t_struct *info)
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
		if (info->plus == 1)
			info->width -= 1;
		while (info->width-- > info->precision)
		{
			if ((info->zero == 1 && info->width != info->precision) || neg == 1)
				write(1, "0", 1);
			else
				write(1, " ", 1);
		}
	}
}
