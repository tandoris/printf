/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clboutry <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 02:26:44 by clboutry          #+#    #+#             */
/*   Updated: 2019/07/30 02:01:00 by clboutry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf(t_struct	*info)
{
	int cmpt_ph;
	int	cmpt_gui;

	cmpt_ph = 0;
	cmpt_gui = 0;
	while(info->phrase[cmpt_ph])
	{
		if (info->phrase[cmpt_ph] != '\'' && cmpt_gui != 2)
		{
			if (info->phrase[cmpt_ph] != '%')
				ft_putchar(info->phrase[cmpt_ph]);
			if (info->phrase[cmpt_ph] == '%')
			{
				ft_putstr(info->arg[info->cmpt]);
				info->cmpt = info->cmpt + 1;
			}
		}
		if (info->phrase[cmpt_ph] == '\'')
			cmpt_gui++;
		cmpt_ph ++;
	}
}




int		main(void)
{
	t_struct	info;
	char		*print_chaine;
	char 		*prenom;
	char		*fruit;
	
	prenom = "lamia";
	fruit = "banane";
	info.cmpt = 0;
	print_chaine = "'salut % , sa va ? tu es une %' , prenom, fruit";
	info.phrase = print_chaine;
	info.arg[0] = prenom;
	info.arg[1] = fruit;
	ft_printf(&info);
	return (0);
}
