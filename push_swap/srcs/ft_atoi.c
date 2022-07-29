/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:51:49 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/30 00:20:07 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_isdigit(int c)
{
	int	ret;

	ret = (c >= '0' && c <= '9');
	if (!ret)
		ft_error("잘못된 입력입니다.\n", 2);
	return (ret);
}

int	ft_atoi(const char *str)
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
	ft_isdigit(str[i]);
	while (str[i] && ft_isdigit(str[i]))
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
