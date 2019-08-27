/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 21:23:44 by clboutry          #+#    #+#             */
/*   Updated: 2019/08/27 21:54:07 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_percent_left(t_struct *info)
{
	write(1, "%", 1);
	while (info->width > 1)
	{
		write(1, " ", 1);
		info->width -= 1;
	}
}

void	ft_print_percent_right(t_struct *info)
{
	while (info->width > 1)
	{
		if (info->zero == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		info->width -= 1;
	}
	write(1, "%", 1);
}



void	ft_print_percent(const char *str, t_struct *info)
{
	if (str[info->cmpt] == '%')
	{
		if (info->minus == 1)
			ft_print_percent_left(info);
		else
			ft_print_percent_right(info);
	}
}
