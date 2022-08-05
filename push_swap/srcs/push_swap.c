/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 03:14:45 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/05 18:04:08 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

// void	display(t_ps *ps)
// {
// 	if (ps->count == 0)
// 		return ;
// 	t_node *node = ps->head;

// 	while (node->next)
// 	{
// 		printf("%d\n", node->data);
// 		node = node->next;
// 	}
// }

void	push_swap(t_ps *a, t_ps *b, int *arr)
{
	int	idx_a;
	int	idx_b;
	// printf("\norigin:\n[ a ]\n");
	// display(a);
	// printf("[ b ]\n");
	// display(b);
	ps_pivot(a, b, arr);
	while (a->count > 3)
		ps_push(a, b, PB);
	if (a->count == 2)
		ps_sort2(a);
	if (a->count == 3)
		ps_sort3(a);
	while (b->count)
	{
		idx_a = 0;
		idx_b = 0;
		// printf("\nbefore:\n[ a ]\n");
		// display(a);
		// printf("[ b ]\n");
		// display(b);
		ps_min_rotate(a, b, &idx_a, &idx_b);
		ps_rotate2(a, b, &idx_a, &idx_b);
		ps_rotate1(a, idx_a, RA, RRA);
		ps_rotate1(b, idx_b, RB, RRB);
		ps_push(b, a, PA);
		// printf("after:\n[ a ]\n");
		// display(a);
		// printf("[ b ]\n");
		// display(b);
	}
	ps_sort_last(a);
}
