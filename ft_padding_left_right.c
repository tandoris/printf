/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_left_right.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 01:40:47 by clboutry          #+#    #+#             */
/*   Updated: 2019/08/21 06:08:05 by clboutry         ###   ########.fr       */
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

void	ft_padding_right(int nbrlen, t_struct *info)
{
	while (info->width)
	{
		write(1, "0", 1);
		info->width--;
	}
}
