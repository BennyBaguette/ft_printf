/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <jabenjam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:15:07 by jabenjam          #+#    #+#             */
/*   Updated: 2020/02/22 02:22:40 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"


void	ft_width_pointer(t_data *f)
{
	int	limit;

	limit = f->len;
	while (f->width - limit > 0)
	{
		if (f->zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		f->width--;
		f->count++;
	}
}

/*
** Mode = 0 : On utilise la len
** Mode = 1 : On utilise la precision
*/

void	ft_width(t_data *f, int mode)
{
	int	limit;

	limit = (mode == 1 ? f->precision : f->len);
	while (f->width - limit > 0)
	{
		if (f->zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		f->width--;
		f->count++;
	}
}
