/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:05:14 by yeblee            #+#    #+#             */
/*   Updated: 2023/01/13 01:19:10 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	t_info	info;

	if (ft_check_valid(ac, av))
		return (1);
	if (ft_init(&info, ac, av))
		return (1);
	if (ft_philo(&info))
		return (1);
	return (0);
}