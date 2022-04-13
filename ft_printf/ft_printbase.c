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

char	*base_type(const char type)
{
	if (type == 'u' || type == 'd')
		return ("0123456789");
	else if (type == 'x' || type == 'p')
		return ("0123456789abcdef");
	else if (type == 'X')
		return ("0123456789ABCDEF");
}

int	ft_printbase(va_list ap, const char format)
{
	int		tmp;
	int		print_length;
	char	*str;
	char	*base;

	base = base_type(format);
	print_length = 0;
	if (format == 'd' || format == 'i')
		str = ft_itoa(va_arg(ap, int), base);
	else if (format == 'u' || format == 'x' || format == 'X')
		str = ft_uitoa(va_arg(ap, unsigned int), base);
	else if (format == 'p')
		str = ft_pitoa(va_arg(ap, unsigned long long), base);
	print_length += ft_printstr(str);
	free(str);
	return (print_length);
}
