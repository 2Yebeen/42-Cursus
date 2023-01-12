/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 23:16:34 by yeblee            #+#    #+#             */
/*   Updated: 2023/01/13 00:49:30 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_check_num(char *str);
static int	ft_check_argv(int ac, char *av[]);

int	ft_check_valid(int ac, char *av[])
{
	if (ac != 5 && ac != 6)
		return (ft_error("Please enter 4 or 5 arguments"));
	if (ft_check_num(av))
		return (ft_error("Please enter only numbers"));
	if (ft_check_argv(ac, av))
		return (ft_error("Please check the arguments"));
	return (0);
}

static int	ft_check_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

static int	ft_check_argv(int ac, char *av[])
{
	if (ft_atoi(av[1]) < 1)
		return (1);
	if (ft_atoi(av[2]) < 0)
		return (1);
	if (ft_atoi(av[3]) < 0)
		return (1);
	if (ft_atoi(av[4]) < 0)
		return (1);
	if (ac == 6)
		if (ft_atoi(av[5]) < 1)
			return (1);
	return (0);
}
