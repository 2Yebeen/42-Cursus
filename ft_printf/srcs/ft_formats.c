/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:00:04 by yeblee            #+#    #+#             */
/*   Updated: 2022/04/15 20:12:45 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_parsing(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == '%')
		print_length += write(1, "%", 1);
	else if (format == 'c')
		print_length += ft_printchar(va_arg(args, int));
	else if (format == 's')
		print_length += ft_printstr(va_arg(args, char *));
	else
		print_length += ft_checkbase(args, format);
	return (print_length);
}

int ft_formats(va_list ap, const char *format)
{
	int	i;
	int	print_length;

	i = 0;
	print_length = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			print_length += ft_parsing(ap, format[i + 1]);
			i++;
		}
		else
			print_length += write(1, (format + i), 1);
		i++;
	}
	return (print_length);
}
