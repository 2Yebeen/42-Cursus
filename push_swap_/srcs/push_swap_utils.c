/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 23:17:10 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/04 21:02:12 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_min_rotate(t_ps *a, t_ps *b, int *idx_a, int *idx_b)
{
	int		i;
	int		i_a;
	int		i_b;
	int		num;
	t_node	*node;

	i = 0;
	node = ps_get_node(b, 0);
	while (i++ < b->count)
	{
		num = b->head->data;
		i_a = ps_location(num, a);
		if (i >= (b->count / 2))
			i_b = (b->count - i) * -1;
		else
			i_b = i;
		if (i == 0 || ps_get_bigger(*idx_a, *idx_b, i_a, i_b))
		{
			*idx_a = i_a;
			*idx_b = i_b;
		}
		node = node->next;
	}
}

int	ps_location(int num, t_ps *ps)
{
	int	ret;

	if (num < ps_data_min(ps->head))
		ret = ps_min(ps);
	else if (num > ps_data_max(ps->head))
		ret = ps_max(ps);
	else
		ret = ps_mid(num, ps);
	return (ret);
}

int	ps_get_bigger(int a, int b, int i_a, int i_b)
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
	else
		return (0);
}
