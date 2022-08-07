/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:25:28 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/07 22:00:20 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char *av[])
{
	int		i;
	t_ps	*a;
	t_ps	*b;
	int		*sorted_array;

	i = 0;
	if (ac >= 2)
	{
		a = ps_create();
		b = ps_create();
		while (++i < ac)
			ps_parsing(av[i], a);
		sorted_array = ps_array_validation(a);
		ps_sort_init(a, b, sorted_array);
		ps_destroy(a);
		ps_destroy(b);
	}
	return (0);
}
