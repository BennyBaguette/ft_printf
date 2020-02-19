/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:14:09 by jabenjam          #+#    #+#             */
/*   Updated: 2020/02/19 11:39:40 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** CP : Ajout du "0x" si il s'agit d'un pointeur
** CP : Si il y a une precision on l'utilise au lieu de len
**		Sinon on utilise la len pour print
** CP : Si il n'y a aucune precision on utilise la len
*/

void	ft_padding_str(char *str, t_data *f)
{
	if (f->pointer)
		ft_putstr_mod("0x", f, 0);
	if (f->precision >= 0)
	{
		ft_width(f, 0);
		ft_putstr_mod(str, f, 1);
	}
	else
		ft_putstr_mod(str, f, 0);
}

/*
** CP : Si il y a une precision et qu'elle est superieure a len
**		On la remplace par cette derniere
*/

void	ft_string(char *str, t_data *f)
{
	if (!str)
		str = "(null)";
	f->len = ft_strlen(str);
	if (f->precision >= 0 && f->precision > f->len)
		f->precision = f->len;
	if (f->left)
		ft_padding_str(str, f);
	if (f->precision >= 0)
		ft_width(f, 1);
	else
		ft_width(f, 0);
	if (!f->left)
		ft_padding_str(str, f);
}

void	ft_char(int c, t_data *f)
{
	if (f->left)
		ft_putchar(c);
	ft_width(f, 0);
	if (!f->left)
		ft_putchar(c);
	f->count++;
}
