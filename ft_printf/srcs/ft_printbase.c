/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:00:04 by yeblee            #+#    #+#             */
/*   Updated: 2022/04/15 20:34:25 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printbase(unsigned long long num, const char *base)
{
	size_t	len;

	len = ft_strlen(base);
	if (num >= len)
	{
		ft_printbase(num / len, base);
		ft_printbase(num % len, base);
	}
	else
	{
		write(1, &base[num % len], 1);
	}
}

int	ft_printi(int n, const char *base)
{
	int		print_length;

	print_length = 0;
	if (n == -2147483648)
	{
		print_length += write(1, "-2147483648", 11);
		return (print_length);
	}
	if (n < 0)
	{
		print_length += write(1, "-", 1);
		n = -n;
	}
	if (n == 0)
		print_length += write(1, "0", 1);
	else
		ft_printbase(n, base);
	while (n)
	{
		print_length += 1;
		n /= 10;
	}
	return (print_length);
}

int	ft_printu(unsigned int n, const char *base)
{
	size_t	base_len;
	int		print_length;

	print_length = 0;
	base_len = ft_strlen(base);
	if (n == 0)
		print_length += write(1, "0", 1);
	else
		ft_printbase(n, base);
	while (n)
	{
		print_length += 1;
		n /= base_len;
	}
	return (print_length);
}

int	ft_printp(unsigned long long n, const char *base)
{
	int					print_length;

	print_length = 0;
	print_length += write(1, "0x", 2);
	if (n == 0)
		print_length += write(1, "0", 1);
	else
		ft_printbase(n, base);
	while (n)
	{
		print_length += 1;
		n /= 16;
	}
	return (print_length);
}
