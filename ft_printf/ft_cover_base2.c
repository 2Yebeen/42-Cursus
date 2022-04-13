/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cover_base2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 12:15:15 by yeblee            #+#    #+#             */
/*   Updated: 2022/04/13 12:15:35 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*rev_str(char *str)
{
	int		size;
	int		cur;
	char	tmp;

	size = ft_strlen(str) - 1;
	cur = 0;
	while (cur < size - cur)
	{
		tmp = str[cur];
		str[cur] = str[size - cur];
		str[size - cur] = tmp;
		cur++;
	}
	return (str);
}

int	pos_in_str(char *str, char c)
{
	int	cur;

	cur = 0;
	while (str[cur] != 0)
	{
		if (str[cur] == c)
			return (cur);
		cur++;
	}
	return (-1);
}

////
int	ft_is_in_base(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i] != 0)
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_check_atoi(char *str, char *base, int len)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != 0 && ft_is_in_base(base, str[i]) != -1)
	{
		num = num * len + ft_is_in_base(base, str[i]);
		i++;
	}
	return (num * sign);
}

int	ft_check_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != 0)
	{
		j = 0;
		while (str[j] != 0)
		{
			if (i != j && str[i] == str[j])
				return (-1);
			j++;
		}
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			return (-1);
		if (str[i] == '+' || str[i] == '-')
			return (-1);
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	nbr;
	int	i;
	int	base_len;

	i = -1;
	nbr = 0;
	base_len = ft_check_base(base);
	if (base_len < 2)
		return (0);
	return (ft_check_atoi(str, base, base_len));
}