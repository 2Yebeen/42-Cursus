/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 00:26:54 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/04 01:14:02 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_init_sort(t_ps *a, t_ps *b, int *sorted)
{
	if (a->count == 2)
		ps_sort2(a);
	else if (a->count == 3)
		ps_sort3(a);
	else if (a->count >= 4)
		ps_push_swap(a, b, sorted);
}

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

void	ps_push_swap(t_ps *a, t_ps *b, int *arr)
{
	ps_pivot(a, b, arr);
	while (a->count > 3)
		ps_push(a, b, PB);
	ps_init_sort(a, b, arr);
	while (b->count)
	{
		return ;	
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