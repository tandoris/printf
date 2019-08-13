/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 00:59:01 by clboutry          #+#    #+#             */
/*   Updated: 2019/08/13 09:43:45 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_precision(const char *str, t_struct *info, va_list ap)
{
	int	tmp_pre;

	if (str[info->cmpt] == '.')
	{
		info->precision_find = 1;
		cmpt++;
		if (str[info->cmpt] > 47 && str[info->cmpt] < 58)
		{
			info->precision = ft_atoi(&str[info->cmpt]);
			while (str[info->cmpt] > 49 && str[info->cmpt] < 58)
				info->cmpt++;
		}
		else if (str[info->cmpt] == '*')
		{
			precision = va_arg(ap, int);
			if (precision >= 0)
				info->precision = precision;
			else
				info->precision_find = 0;
			while (str[info->cmpt] == '*')
				cmpt++;
		}
	}
}

void	ft_width(const char *str, t_struct *info, va_list ap)
{
	while ((str[info->cmpt] > 47 && str[info->cmpt] < 58) 
		|| (str[info->cmpt] == '*'))
	{
		if(str[info->cmpt] > 47 && str[info->cmpt] < 58)
		{
			info->width = ft_atoi(&str[info->cmpt]);
			while (str[info->cmpt] > 47 && str[info->cmpt] < 58)
				info->cmpt++;
		}
		if (str[info->cmpt] == '*')
		{
			info->width = va_arg(ap, int);
			info->minus = (info->width < 0) ? 1 : info->minus;
			info->width = (info->width < 0) ? -info->width : info->width;
			info->cmpt++;
		}
	}
}

void	ft_flag(const char *str, t_struct *info)
{
	info->cmpt++;
	while (str[info->cmpt] == '#' || str[info->cmpt] == '0'
	|| str[info->cmpt] == '-' || str[info->cmpt] == '+'
	|| str[info->cmpt] == ' ')
	{
		if (str[info->cmpt] == '#')
			info->hash = 1;
		if (str[info->cmpt] == '0')
			info->zero = 1;
		if (str[info->cmpt] == '-')
			info->minus = 1;
		if (str[info->cmpt] == '+')
			info->plus = 1;
		if (str[info->cmpt] == ' ')
			info->space = 1;
		info->cmpt++;
	}
	if (info->plus == 1)
		info->space = 0;
}

void	ft_parsing(const char *str, t_struct *info, va_list ap)
{
	ft_flag(str, info);
	ft_width(str, info,  ap);
	ft_precision(str, info, ap);
}
