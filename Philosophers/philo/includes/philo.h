/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:05:09 by yeblee            #+#    #+#             */
/*   Updated: 2023/01/13 00:46:21 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include "structures.h"

# define MAX_INT 2147483647

# define TRUE			1
# define FALSE			0

# define LEFT			0
# define RIGHT			1

/* init */
int	ft_init(t_info *info, int ac, char *av[]);

/* philo */
int	ft_philo(t_info *info);

/* utils */
int	ft_error(char *str);
int	ft_atoi(const char *str);

/* vaild */
int	ft_check_valid(int ac, char *av[]);

#endif