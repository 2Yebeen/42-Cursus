/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:47:34 by yeblee            #+#    #+#             */
/*   Updated: 2022/04/14 12:57:08 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int 아닐 경우 -1, NULL일 경우 (null) 출력

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		print_length;

	i = 0;
	print_length = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			print_length += ft_formats(args, format[i + 1]);
			i++;
		}
		else
			print_length += write(1, (format + i), 1);
		i++;
	}
	va_end(args);
	return (print_length);
}