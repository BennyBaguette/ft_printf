/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabenjam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:47:18 by jabenjam          #+#    #+#             */
/*   Updated: 2019/11/18 19:43:48 by jabenjam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int		ft_abs(int n)
{
	return (n < 0 ? (int64_t)-n : (int64_t)n);
}

int			ft_strlen(char *str)
{
	int			len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	uc;
	unsigned char	*dst;

	i = 0;
	uc = c;
	dst = b;
	while (len--)
		dst[i++] = uc;
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	if (n == 0)
		return ;
	else
		ft_memset(s, 0, n);
}

char		*ft_strrev(char *str)
{
	int			i;
	int			len;
	char		tmp;

	len = 0;
	while (str[len])
		len += 1;
	i = -1;
	while (++i < --len)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
	}
	str[i] = '\0';
	return (str);
}

int			ft_ilen(unsigned int n, int mode)
{
	int64_t		len;
	int64_t		nb;

	len = 0;
	if (n < 0)
		len++;
	nb = ft_abs(n);
	while (nb > mode)
	{
		nb = nb / mode;
		len++;
	}
	return (len + 1);
}

int		ft_atoi(const char *str)
{
	int					i;
	size_t				result;
	int					sign;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = str[i++] == '-' ? -1 : 1;
	while (str[i] >= '0' && str[i] <= '9')
		result = (result * 10) + (str[i++] - 48);
	return (result * sign);
}