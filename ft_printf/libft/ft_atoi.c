/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:15:52 by yeblee            #+#    #+#             */
/*   Updated: 2022/03/26 15:19:17 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t				i;
	int					sign;
	unsigned long long	max;
	unsigned long long	num;

	i = 0;
	num = 0;
	sign = 1;
	max = 9223372036854775807;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		if (num > max && sign == 1)
			return (-1);
		else if (num > max + 1 && sign == -1)
			return (0);
		i++;
	}
	return (num * sign);
}
