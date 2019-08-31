/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 05:32:24 by clboutry          #+#    #+#             */
/*   Updated: 2018/11/25 01:29:03 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int	cmpt;

	cmpt = 0;
	if (s && f)
	{
		while (s[cmpt])
		{
			(*f)(&s[cmpt]);
			cmpt++;
		}
	}
}
