/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 04:47:24 by clboutry          #+#    #+#             */
/*   Updated: 2019/08/20 03:10:04 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		main(void)
{
	char	*truc;
	int 	a;

	a = 256;
	truc = "tazwrxytcu";

	printf("%#+ 05.3d", a);
	//write(1, &a, 2);
	return(0);
}
