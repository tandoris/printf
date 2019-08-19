/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboukrou <lboukrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 02:56:40 by lboukrou          #+#    #+#             */
/*   Updated: 2019/08/19 03:57:24 by lboukrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**      Types conversions
**
**  conversions         taille      type                    valeur min / max
**  - d,i               Rien        signed int              -2147483648 / 2147483647
**                      h           short int               -32768 / 32767
**                      l           long int                -2147483648 / 2147483647
**     (signed int)     hh          signed char             -128 / 127
**                      ll          long long int           −9223372036854775807 / 9223372036854775807]
**                      L            ------
** 
**  - o,u,x,X           Rien        unsigned int            4294967295
**                      h           unsigned short int      65535
**                      l           unsigned long int       4294967295
**    (unsigned int)    hh          unsigned char           255
**                      ll          unsigned long long int  18446744073709551615 
**                      L           -------
**
**  - f                 l           ? long double ? 
**                      L           long double             -1 × 10^37 / 1 × 10^37
**    (float,double)
**
**                ------------------------------------------------------
**
** o ---> unsigned octal int (Base 8)
** u ---> unsigned decimal int (meme comportement que d,i avec int positifs
**                             Voir comportement avec int negatif
**                             Maybe ? Int negatifs --> Max + int negatif (Max = 4294967295))
** x ---> unsigned hexadecimal int (Base 16)
** X ---> unsigned hexadecimal int (Base 16 en majuscules)
**
**
**

