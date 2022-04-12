/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 19:42:22 by yeblee            #+#    #+#             */
/*   Updated: 2022/04/12 19:42:23 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *base_type(const char *type)
{
	if (type == 'u' || type == 'd')
		return ("0123456789");
	else if (type == 'x' || type == 'p')
		return ("0123456789abcdef");
	else if (type == 'X')
		return ("0123456789ABCDEF");
}

int   ft_printbase(va_list arge, const char *format)
{
	char    *str;
	char    *base;
	int     print_length;

	base = base_type(format);
	print_length = 0
	if (format == 'd' || format == 'i')
		str = ft_printnbr(va_arg(ap, int), format, base);
	else if (format == 'u' || format == 'x' || format == 'X')
		str = ft_printnbr(va_arg(ap, unsigned int), format, base);
	else if (format == 'p')
	{
		print_length += write(1, "0x", 2);
		str = ft_printnbr(va_arg(ap, unsigned long long), format, base);
	}
	print_length += write(1, str, ft_strlen(str));
	return (print_length);
}