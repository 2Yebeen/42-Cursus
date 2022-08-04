/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:55:23 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/04 18:55:36 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_ps	*ps_create(void)
{
	t_ps	*ps;

	ps = (t_ps *)ft_calloc(1, sizeof(t_ps));
	return (ps);
}

int	ps_push_top(t_ps *ps, int data)
{
	t_node	*buf;
	t_node	*new;

	new = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!new)
		return (FALSE);
	new->data = data;
	if (ps->count == 0)
		ps->head = new;
	else
	{
		buf = ps_get_node(ps, ps->count - 1);
		buf->prev = new;
		new->next = buf;
	}
	ps->count += 1;
	return (TRUE);
}

int	ps_push_bottom(t_ps *ps, int data)
{
	t_node	*buf;
	t_node	*new;

	new = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!new)
		return (FALSE);
	new->data = data;
	if (ps->count == 0)
		ps->head = new;
	else
	{
		buf = ps_get_node(ps, ps->count - 1);
		buf->next = new;
		new->prev = buf;
	}
	ps->count += 1;
	return (TRUE);
}

t_node	*ps_pop_top(t_ps *ps)
{
	t_node	*top;

	top = ps->head;
	ps->head = top->next;
	ps->head->prev = NULL;
	top->next = NULL;
	ps->count--;
	return (top);
}

t_node	*ps_pop_bottom(t_ps *ps)
{
	t_node	*bottom;

	bottom = ps_get_node(ps, ps->count - 1);
	bottom->prev->next = NULL;
	bottom->prev = NULL;
	ps->count--;
	return (bottom);
}
