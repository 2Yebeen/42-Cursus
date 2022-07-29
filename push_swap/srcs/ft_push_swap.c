/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 23:02:06 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/30 01:59:53 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_stack *stack)
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

// t_node	*ft_pop(t_stack *stack)
// {
// 	t_node	*top;
	
// 	top = stack->header.r_link;
// 	stack->header.r_link = top->r_link;
// 	top->r_link->l_link = ft_get_node(stack, --stack->count);
// 	top->l_link->r_link = ft_get_node(stack, 1);
// 	top->l_link = NULL;
// 	top->r_link = NULL;
// 	return (top);
// }

// void	ft_push(t_stack *stack_a, t_stack *stack_b)
// {
// 	t_node *buf;
// 	t_node *top;
	
// 	if (!stack_b->count)
// 		return ;
// 	// top = ft_pop(stack_b);
// 	if (!stack_a->count)
// 		ft_add_data(stack_a, top->data, 0);
// 	else
// 	{		
// 		buf = stack_a->header.r_link;
// 		top->r_link = buf;
// 		top->l_link = buf->l_link;
// 		buf->r_link->r_link = top;
// 		buf->l_link = top;
// 		stack_a->header.r_link = top;
// 		stack_a->count++;
// 	}
// }