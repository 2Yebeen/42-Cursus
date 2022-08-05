/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 03:29:29 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/05 11:48:42 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	ps_min_rotate(t_ps *a, t_ps *b, int *idx_a, int *idx_b)
{
	int		i;
	int		i_a;
	int		i_b;
	t_node	*node;

	i = 0;
	node = b->head;
	while (i < b->count)
	{
		i_a = ps_get_index(node->data, a);
		if (i >= (b->count / 2))
			i_b = (b->count - i) * -1;
		else
			i_b = i;
		if (i == 0 || ps_bigger(*idx_a, *idx_b, i_a, i_b))
		{
			*idx_a = i_a;
			*idx_b = i_b;
		}
		node = node->next;
		i++;
	}
}

int	ps_get_index(int num, t_ps *ps)
{
	if (num < ps_data_min(ps->head))
		return (ps_min(ps));
	else if (num > ps_data_max(ps->head))
		return (ps_max(ps));
	else
		return (ps_mid(num, ps));
}

int	ps_bigger(int a, int b, int i_a, int i_b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (i_a < 0)
		i_a *= -1;
	if (i_b < 0)
		i_b *= -1;
	if (a + b > i_a + i_b)
		return (1);
	return (0);
}
