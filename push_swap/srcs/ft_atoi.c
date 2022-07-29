/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:51:49 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/29 15:08:38 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	ft_isdigit(int c, int *err)
{
	int	ret;

	ret = (c >= '0' && c <= '9');
	if (!ret)
		*err = 0;
	return (ret);
}

int	ft_atoi(const char *str, int *err)
{
	size_t				i;
	int					sign;
	unsigned long long	num;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	ft_isdigit(str[i], err);
	while (str[i] && ft_isdigit(str[i], err))
	{
		num = (num * 10) + (str[i] - '0');
		if (num > LONG_MAX && sign == 1)
			return (-1);
		else if (num - 1 > LONG_MAX && sign == -1)
			return (0);
		i++;
	}
	return (num * sign);
}
