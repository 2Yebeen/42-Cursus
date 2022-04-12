/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:06:49 by yeblee            #+#    #+#             */
/*   Updated: 2022/04/12 17:09:17 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_baselen(char *base)
{
	int	len;

	len = 0;
	return (len);
}

int	ft_putnbr(void n, int base)
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
	div = n / base;
	mod = n % base;
	if (div != 0)
		ft_putnbrd(div);
	ans = mod + '0';
	print_length += ft_putchar(&ans);
	return (print_length);
}

int	ft_printbase(va_list args, const char format)
{
	int		i;
	int		base_len;
	int		print_length;
	char	base;

	print_length = 0;
	if (format == 'u' || format == 'i' || format == 'u')
		base = BASE_10;
	else if (format == 'p' || format == 'X')
		base = BASE__;
	else if (fotmat == 'x')
		base = BASE_;
	base_len = ft_baselen(base);
	if (format == 'p')
	{
		print_length += write(1, "0x", 2);
		print_length += ft_putnbr(va_arg(args, unsigned long long), base_len);
	}
	else if (format == 'd' || format == 'i')
		print_length += ft_putnbr(va_arg(args, int), base_len);
	else if (format == 'u')
		print_length += ft_putnbr(va_arg(args, unsigned int), base_len);
	else if ((format == 'x') || (format == 'X'))
		print_length += ft_putnbr(va_arg(args, unsigned int), base_len);
	return (print_length);
}
