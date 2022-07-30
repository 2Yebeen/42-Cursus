/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 23:02:01 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/30 11:12:54 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ps_create_stack(t_stack *stack)
{
	t_stack	*new;

	new = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!new)
		ps_error("ft_create_stack중 할당에 실패했습니다.\n", 2);
	return (new);
}

int	ps_add_data(t_stack *stack, int data)
{
	t_node	*buf;
	t_node	*new;

	new = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!new)
		return (FALSE);
	new->data = data;
	if ((stack->count) == 0)
	{
		stack->header.r_link = new;
		new->l_link = new;
		new->r_link = new;
	}
	else
	{
		buf = ps_get_node(stack, stack->count - 1);
		new->l_link = buf;
		new->r_link = buf->r_link;
		buf->r_link->l_link = new;
		buf->r_link = new;
	}
	stack->count += 1;
	return (TRUE);
}

t_node	*ps_get_node(t_stack *stack, int position)
{
	t_node	*buf;

	buf = stack->header.r_link;
	while (position)
	{
		buf = buf->r_link;
		position -= 1;
	}
	return (buf);
}

void	ps_clear(t_stack *stack)
{
	t_node	*clear;
	t_node	*next;
	
	clear = stack->header.r_link;
	while (stack->count)
	{
		next = clear->r_link;
		clear->data = 0x00;
		clear->l_link = NULL;
		clear->r_link = NULL;
		free(clear);
		clear = next;
		stack->count -= 1;
	}
	clear = NULL;
	next = NULL;
}

void	ps_delete(t_stack *stack)
{
	ps_clear(stack);
	stack->header.r_link = NULL;
	stack->header.l_link = NULL;
	stack->count = 0;
	free(stack);
	stack = NULL;
}
