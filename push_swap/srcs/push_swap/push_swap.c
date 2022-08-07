/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 03:14:45 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/05 20:48:49 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_ps *a, t_ps *b, int *arr)
{
	int	idx_a;
	int	idx_b;

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
		ps_min_rotate(a, b, &idx_a, &idx_b);
		ps_rotate2(a, b, &idx_a, &idx_b);
		ps_rotate1(a, idx_a, RA, RRA);
		ps_rotate1(b, idx_b, RB, RRB);
		ps_push(b, a, PA);
	}
	ps_sort_last(a);
}
