/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 22:34:17 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/04 01:35:14 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	display(t_ps *ps)
{
	t_node *node;
	int	i;

	i = ps->count;
	node = ps->head;
	while(i--)
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
	int		*sorted;

	i = 0;
	if (ac >= 2)
	{		
		a = ps_create();
		b = ps_create();
		while (++i < ac)
			ps_parsing(av[i], a);
		sorted = ps_arr(a);
		ps_init_sort(a, b, sorted);
	}
	return (0);
}
