/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 00:26:54 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/04 20:27:13 by yeblee           ###   ########.fr       */
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
	else
		ps_error(2);
}

void	ps_push_swap(t_ps *a, t_ps *b, int *arr)
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
		ps_rr(a, b, &idx_a, &idx_b);
		ps_rr_ab(a, idx_a, RA, RRA);
		ps_rr_ab(b, idx_b, RB, RRB);
		ps_push(b, a, PA);
	}
	ps_sort_last(a);
}

void	ps_sort_last(t_ps *a)
{
	int	i;
	int	min;

	min = ps_data_min(a->head->data);
	i = ps_min(a);
	ps_rr_ab(a, i, RA, RRA);
}

int	ps_data_min(t_ps *ps)
{
	int		num;
	t_node	*node;

	node = ps->head;
	num = node->data;
	while (node)
	{
		if (num > node->data)
			num = node->data;
		node = node->next;
	}
	return (num);
}

int	ps_min(t_ps *ps)
{
	int		i;
	int		tmp;
	int		ret;
	t_node	*node;

	ret = 0;
	tmp = 0;
	node = ps->head;
	i = ps_data_min(ps);
	while (node)
	{
		tmp = node->data;
		if (tmp == i)
			break ;
		ret++;
		node = node->next;
	}
	if (ret >= (ps->count) / 2)
		ret = (ps->count - ret) * -1;
	return (ret);
}

int	ps_max(t_ps *ps)
{
	int		i;
	int		tmp;
	int		ret;
	t_node	*node;

	ret = 0;
	tmp = 0;
	node = ps->head;
	i = ps_data_max(ps);
	while (node)
	{
		tmp = node->data;
		if (tmp == i)
			break ;
		ret++;
		node = node->next;
	}
	ret++;
	if (ret >= (ps->count) / 2)
		ret = (ps->count - ret) * -1;
	return (ret);
}

int	ps_mid(int num, t_ps *ps)
{
	int		ret;
	t_node	*node;

	node = ps->head;
	i = 1;
	while (node->next)
	{
		if (num > ps->head->data && num < ps->head->next->data)
			break ;
		ret++;
		node = node->next;
	}
	if (ret >= (ps->count) / 2)
		ret = (ps->count - ret) * -1;
	return (ret);
}

int	ps_data_max(t_ps *ps)
{
	int		num;
	t_node	*node;

	node = ps->head;
	num = node->data;
	while (node)
	{
		if (num < node->data)
			num = node->data;
		node = node->next;
	}
	return (num);
}