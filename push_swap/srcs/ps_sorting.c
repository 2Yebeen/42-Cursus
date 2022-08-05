/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 02:33:14 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/05 03:47:49 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_sort_init(t_ps *a, t_ps *b, int *sorted_array)
{
	if (a->count == 2)
		ps_sort2(a);
	else if (a->count == 3)
		ps_sort3(a);
	else if (a->count >= 4)
		push_swap(a, b, sorted_array);
}

void	ps_sort2(t_ps *a)
{
	if (a->head->data > a->head->next->data)
		ps_swap(a, SA);
}

void	ps_sort3(t_ps *a)
{
	int	left;
	int	right;
	int	mid;

	left = a->head->data;
	mid = a->head->next->data;
	right = a->head->next->next->data;
	if (right > left && left > mid)
		ps_swap(a, SA);
	if (mid > left && left > right)
		ps_reverse_rotate(a, RRA);
	if (left > right && right > mid)
		ps_rotate(a, RA);
	if (mid > right && right > left)
	{
		ps_swap(a, SA);
		ps_rotate(a, RA);
	}
	if (left > mid && mid > right)
	{
		ps_swap(a, SA);
		ps_reverse_rotate(a, RRA);
	}
}

void	ps_sort_last(t_ps *a)
{
	int	i;
	
	i = ps_min(a);
	ps_rotate1(a, i, RA, RRA);
}
