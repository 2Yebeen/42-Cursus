/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:56:30 by yeblee            #+#    #+#             */
/*   Updated: 2022/03/31 21:22:19 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h> 

int	ft_putnbr(int n)
{
	int	div;
	int	mod;
	int	ans;
	int	print_length;

	print_length = 0;
	if (n == -2147483648)
	{
		print_length += ft_putstr("-2147483648");
		return (print_length);
	}
	if (n < 0)
	{
		print_length += ft_putchar("-");
		n *= -1;
	}
	div = n / 10;
	mod = n % 10;
	if (div != 0)
		ft_putnbr_fd(div);
	ans = mod + '0';
	print_length += ft_putchar(&ans);
	return (print_length);
}

int	ft_change(unsigned int nbr, char *base, int len)
{
	int	i;

	i = nbr % len;
	if (nbr / len != 0)
		ft_change(nbr / len, base, len);
	return (ft_putchar(&base[i]));
}

int	ft_putnbr_base(unsigned int nbr, char format)
{
	char			*base;
	int				print_length;
	unsigned int	nbrl;

	nbrl = nbr;
	if (format == 'x')
		base = "0123456789abcdef";
	else if (format == 'X')
		base = "0123456789ABCDEF";
	if (nbrl < 0)
	{
		print_length += ft_putchar("-");
		nbrl *= -1;
	}
	print_length += ft_putstr("0x");
	print_length += ft_change(nbrl, base, 16);
	return (print_length);
}
