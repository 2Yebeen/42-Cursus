/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:55:47 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/29 15:12:36 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

int	main(int ac, char *av[])
{
	int		i;
	int		idx;
	int		num;
	int		err;
	char	**temp;

	err = 1;
	if (ac > 2)
	{
		i = 0;
		while (av[++i])
		{
			idx = 0;
			temp = ft_split(av[i], ' ');
			while (temp[idx])
			{
				if (!err)
					exit(0);
				// ft_push(num);
				idx++;
			}
		}
	}
	return (0);
}
