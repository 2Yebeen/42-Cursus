/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 23:02:06 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/30 11:22:36 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_swap(t_stack *stack)
{
	t_node	*top;
	t_node	*next;
	int	temp;

	top = stack->header.r_link;
	next = top->r_link;
	temp = top->data;
	top->data = next->data;
	next->data = temp;
}

t_node	*ps_pop(t_stack *stack)
{
	t_node	*ret;

	ret = stack->header.r_link;
	stack->header.r_link = ret->r_link;
	ret->l_link->r_link = ret->r_link;
	ret->r_link->l_link = ret->l_link;
	ret->l_link = NULL;
	ret->r_link = NULL;
	stack->count--;
	ps_display(stack);
	return (ret);
}

void	ps_push(t_stack *stack_a, t_stack *stack_b)
{
	t_node *buf;
	t_node *top;
	
	if (!stack_b->count)
		return ;
	top = ps_pop(stack_b);
	if (!stack_a->count)
		ps_add_data(stack_a, top->data);
	else
	{		
		buf = stack_a->header.r_link;
		top->r_link = buf;
		top->l_link = buf->l_link;
		buf->r_link->r_link = top;
		buf->l_link = top;
		stack_a->header.r_link = top;
		stack_a->count++;
	}
	free(top);
	top = NULL;
}