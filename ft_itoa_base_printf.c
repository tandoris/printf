/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 04:29:03 by clboutry          #+#    #+#             */
/*   Updated: 2019/08/26 19:54:48 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_itoa_base_printf(intmax_t nbr, int base)
{
	int			len;
	intmax_t	nbr2;
	char		*mall;
	char		*ret;

	len = 1;
	nbr2 = nbr;
	if (nbr < -9223372036854775807)
		return (write(1, "223372036854775808", 19));
	while (nbr2 /= base)
		len++;
	if (!(ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	mall = ft_strdup("0123456789ABCDEF");
	ret[len] = '\0';
	while (len-- > 0)
	{
		ret[len] = mall[nbr % base];
		nbr /= base;
	}
	len = ft_strlen(ret);
	write(1, ret, len);
	free(mall);
	free(ret);
	return (len);
}
