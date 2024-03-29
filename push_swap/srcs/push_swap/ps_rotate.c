/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 03:33:37 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/05 20:38:44 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_rotate1(t_ps *ps, int idx, int type1, int type2)
{
	while (idx)
	{
		if (idx > 0)
		{
			ps_rotate(ps, type1);
			idx -= 1;
		}
		else
		{
			ps_reverse_rotate(ps, type2);
			idx += 1;
		}
	}
}

void	ps_rotate2(t_ps *a, t_ps *b, int *idx_a, int *idx_b)
{
	while (*idx_a && *idx_b && (*idx_a > 0 && *idx_b > 0))
	{
		ps_rotate(a, NONE);
		ps_rotate(b, NONE);
		ps_display(RR);
		*idx_a = *idx_a - 1;
		*idx_b = *idx_b - 1;
	}
	while (*idx_a && *idx_b && (*idx_a < 0 && *idx_b < 0))
	{
		ps_reverse_rotate(a, NONE);
		ps_reverse_rotate(b, NONE);
		ps_display(RRR);
		*idx_a = *idx_a + 1;
		*idx_b = *idx_b + 1;
	}
}

void	ps_rotate(t_ps *ps, int type)
{
	t_node	*node;

	if (ps->count > 1)
	{		
		node = ps_left_pop(ps);
		if (!node)
			return ;
		if (!ps_right_add(ps, node->data))
			ps_error(2);
		ps_display(type);
		free(node);
		node = NULL;
	}
}

void	ps_reverse_rotate(t_ps *ps, int type)
{
	t_node	*node;

	if (ps->count > 1)
	{		
		node = ps_right_pop(ps);
		if (!node)
			return ;
		if (!ps_left_add(ps, node->data))
			ps_error(2);
		ps_display(type);
		free(node);
		node = NULL;
	}
}
