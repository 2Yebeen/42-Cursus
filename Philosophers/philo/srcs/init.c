/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 00:40:47 by yeblee            #+#    #+#             */
/*   Updated: 2023/01/13 01:42:18 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_init_input(t_input *input, int ac, char *av[]);
static int	ft_init_mutex(t_info *info);
static int	ft_init_philo(t_info *info);

int	ft_init(t_info *info, int ac, char *av[])
{
	info->end = 0;
	info->start = 0;
	ft_init_input(info->input, ac, av);
	if (ft_init_mutex(info))
		return (1);
	if (ft_init_philo(info))
		return (1);

	return (0);
}

static void	ft_init_input(t_input *input, int ac, char *av[])
{
	input->philos_num = ft_atoi(av[1]);
	input->time_to_die = ft_atoi(av[2]);
	input->time_to_eat = ft_atoi(av[3]);
	input->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		input->must_eat_num = ft_atoi(av[5]);
	else
		input->must_eat_num = -1;
}

static int	ft_init_mutex(t_info *info)
{
	int				nbr_ph;
	pthread_mutex_t	*mutex;

	nbr_ph = info->input->philos_num;
	mutex = malloc(sizeof(pthread_mutex_t) * nbr_ph);
	while (nbr_ph--)
		pthread_mutex_init(&mutex[nbr_ph], NULL);
	pthread_mutex_init(&info->lock_print, NULL);
	info->forks = mutex;
	return (0);
}

static int	ft_init_philo(t_info *info)
{
	int	i;

	i = 0;
	info->philo = malloc(sizeof(t_philo) * info->input->must_eat_num);
	if (!info->philo)
		return (ft_error("Failed to allocate memory."));
	while (i < info->input->must_eat_num)
	{
		info->philo[i].p_id = i;
		info->philo[i].fork[LEFT] = i;
		info->philo[i].fork[RIGHT] = (i + 1) % info->input->must_eat_num;
		info->philo[i].dead = 0;
		info->philo[i].eat_cnt = 0;
		info->philo[i].info = info;
		i++;
	}
	return (0);
}
