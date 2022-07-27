/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:05:17 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/27 11:24:36 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	size_t	i;
	long	ret;
	int		m_flag;

	i = 0;
	m_flag = 0;
	ret = 0;
	while (str[i] == 9 || str[i] == 10 || str[i] == 11 || \
	str[i] == 12 || str[i] == 13 || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		m_flag = str[i++] - '+';
	while ('0' <= str[i] && str[i] <= '9')
	{
		ret *= 10;
		ret += str[i] - '0';
		i++;
	}
	if (m_flag != 0)
		ret *= -1;
	return (ret);
}

double	ft_atof(const char *str)
{
	int		len;
	int		m_flag;
	int		i;
	double	ret;
	double	temp;

	i = 0;
	m_flag = 1;
	len = ft_strlen(str);
	if (str[0] == '-')
	{
		m_flag = -1;
		i++;
	}
	ret = ft_atol(str);
	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (str[i] == '.')
		i++;
	temp = ft_atol(str + i);
	i = len - i;
	while (i--)
		temp /= 10;
	return (m_flag * (ret + temp));
}
