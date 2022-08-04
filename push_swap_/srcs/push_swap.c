/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 23:43:03 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/04 01:57:04 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_swap(t_ps *ps, int type)
{
	int	data;

	if (ps->count >= 2)
	{		
		data = ps->head->data;
		ps->head->data = ps->head->next->data;
		ps->head->next->data = data;
		ps_display(type);
	}
}

void	ps_push(t_ps *a, t_ps *b, int type)
{
	t_node	*node;
	
	if (a->count)
	{		
		node = ps_pop_top(a);
		ps_push_top(b, node->data);
		ps_display(type);
		free(node);
		node = NULL;
	}
}

void	ps_rotate(t_ps *ps, int type)
{
	t_node *node;
	
	if (ps->count)
	{		
		node = ps_pop_top(ps);
		if (!ps_push_bottom(ps, node->data))
			ps_error(2);
		ps_display(type);
		free(node);
		node = NULL;
	}
}

void	ps_reverse_rotate(t_ps *ps, int type)
{
	t_node *node;
	
	if (ps->count)
	{		
		node = ps_pop_bottom(ps);
		if (!ps_push_top(ps, node->data))
			ps_error(2);
		ps_display(type);
		free(node);
		node = NULL;
	}
}

t_node	*ps_get_node(t_ps *ps, int position)
{
	t_node	*buf;

	buf = NULL;
	if (position)
		buf = ps->head;
	while (position--)
		buf = buf->next;
	return (buf);
}