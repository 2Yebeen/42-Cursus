/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:59:37 by yeblee            #+#    #+#             */
/*   Updated: 2023/01/13 01:29:34 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "philo.h"

typedef struct s_input	t_input;
typedef struct s_info	t_info;
typedef struct s_philo	t_philo;

struct s_input
{
	int	philos_num;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat_num;
};

struct s_info
{
	t_input			*input;
	t_philo			*philo;
	time_t			start;
	int				end;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock_print;
};

struct s_philo
{
	int				p_id;
	int				fork[2];
	int				eat_cnt;
	time_t			dead;
	pthread_t		thread_id;
	t_info			*info;
};

#endif
