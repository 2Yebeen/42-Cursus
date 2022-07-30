/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkbase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 12:06:20 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/30 10:44:38 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*base_type(const char type)
{
	if (type == 'u' || type == 'd' || type == 'i')
		return ("0123456789");
	else if (type == 'x' || type == 'p')
		return ("0123456789abcdef");
	else if (type == 'X')
		return ("0123456789ABCDEF");
	return (0);
}

int	ft_checkbase(va_list ap, const char format)
{
	int		print_length;
	char	*base;

	base = base_type(format);
	print_length = 0;
	if (format == 'd' || format == 'i')
		print_length += ft_printi(va_arg(ap, int), base);
	else if (format == 'u' || format == 'x' || format == 'X')
		print_length += ft_printu(va_arg(ap, unsigned int), base);
	else if (format == 'p')
		print_length += ft_printp(va_arg(ap, unsigned long long), base);
	return (print_length);
}
