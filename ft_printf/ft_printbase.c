/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 12:06:20 by yeblee            #+#    #+#             */
/*   Updated: 2022/04/13 19:23:23 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*base_type(const char *type)
{
	if (type == 'u' || type == 'd')
		return ("0123456789");
	else if (type == 'x' || type == 'p')
		return ("0123456789abcdef");
	else if (type == 'X')
		return ("0123456789ABCDEF");
	return (0);
}

int	ft_printbase(va_list ap, const char format)
{
	int		tmp;
	int		print_length;
	char	*base;

	base = base_type(format);
	print_length = 0;
	if (format == 'd' || format == 'i')
		print_length += ft_itoa(va_arg(ap, int));
	else if (format == 'u' || format == 'x' || format == 'X')
		print_length += ft_printnbr(va_arg(ap, unsigned int), format, base);
	else if (format == 'p')
	{
		tmp = va_arg(ap, unsigned long long);
		print_length += write(1, "0x", 2);
		print_length += ft_printnbr((unsigned long long)tmp, format, base);
	}
	return (print_length);
}
