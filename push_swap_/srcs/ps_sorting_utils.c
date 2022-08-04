/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:54:32 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/04 20:40:47 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_sort2(t_ps *a)
{
	if (a->head->data > a->head->next->data)
		ps_swap(a, SA);
}

void	ps_sort3(t_ps *a)
{
	int	top;
	int	middle;
	int	bottom;

	top = a->head->data;
	middle = a->head->next->data;
	bottom = a->head->next->next->data;
	if (top > middle && bottom > top && bottom > middle)
		ps_swap(a, SA);
	if (top > middle && top > bottom && bottom > middle)
		ps_rotate(a, RA);
	if (middle > top && top > bottom && middle > bottom)
		ps_reverse_rotate(a, RRA);
	if (top > middle && middle > bottom)
	{
		ps_swap(a, SA);
		ps_reverse_rotate(a, RRA);
	}
	if (top < middle && top < bottom)
	{
		ps_swap(a, SA);
		ps_rotate(a, RA);
	}
}

void	ps_pivot(t_ps *a, t_ps *b, int *arr)
{
	int	i;
	int	pivot1;
	int	pivot2;

	pivot1 = arr[a->count / 3];
	pivot2 = arr[(a->count * 2) / 3];
	i = a->count;
	while (i--)
	{
		if (a->head->data >= pivot2)
			ps_reverse_rotate(a, RA);
		else
		{
			ps_push(a, b, PB);
			if (b->head->data < pivot1)
				ps_rotate(b, RB);
		}
	}
}

void	ps_rr(t_ps *a, t_ps *b, int *idx_a, int *idx_b)
{
	while (*idx_a && *idx_b && (*idx_a > 0 && *idx_b > 0))
	{
		ps_rotate(a, NONE);
		ps_rotate(b, NONE);
		ps_display(RR);
		*idx_a--;
		*idx_b--;
	}
	while (*idx_a && *idx_b && (*idx_a < 0 && *idx_b < 0))
	{
		ps_reverse_rotate(a, NONE);
		ps_reverse_rotate(b, NONE);
		ps_display(RRR);
		*idx_a++;
		*idx_b++;
	}
}

void	ps_rr_ab(t_ps *ps, int idx, int type1, int type2)
{
	while (idx)
	{
		if (idx-- > 0)
			ps_rotate(ps, type1);
		else
		{
			ps_reverse_rotate(ps, type2);
			idx++;
		}
	}
}
