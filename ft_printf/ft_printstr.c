/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:03:21 by yeblee            #+#    #+#             */
/*   Updated: 2022/04/12 19:25:31 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_printchar(int chr)
{
	unsigned char	c;

	c = (unsigned char)chr;
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	print_length;

	if (!str)
	{
		print_length = write(1, "(null)", 6);
		return (print_length);
	}
	print_length = write(1, str, ft_strlen(str));
	return (print_length);
}
