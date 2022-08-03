/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 22:34:17 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/03 11:37:51 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char *av[])
{
	int		i;
	t_ps	*a;
	t_ps	*b;
	int		*sorted;

	if (ac <= 2)
		return (0);
	i = 0;
	a = ps_create();
	b = ps_create();
	while (++i < ac)
		ps_parsing(av[i], a);
	sorted = ps_arr(a);
	ps_init_sort(a, b, sorted);
	return (0);
}
