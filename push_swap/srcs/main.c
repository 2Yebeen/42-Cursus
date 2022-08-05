/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:25:28 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/05 18:06:23 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	display(t_ps *ps)
{
	int	i=0;
	if (ps->count == 0)
		return ;
	t_node *node = ps->head;

	while (i++ < ps->count)
	{
		printf("%d\n", node->data);
		node = node->next;
	}
}

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
		// ps_check_sorted();
		ps_sort_init(a, b, sorted_array);
		display(a);
	}
	return (0);
}
