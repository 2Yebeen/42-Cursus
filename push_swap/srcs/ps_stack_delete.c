/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_delete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:17:13 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/02 16:19:08 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Front 제거 : front는 다음 노드를 가리키고 처음 노드 연결 끊음
t_node	*ps_delete_front(t_stack *stack)
{
	t_node	*node;

	node = ps_peek_front(stack);
	if (node != NULL)
	{
		if (stack->count == 1)
			stack->rear = NULL;
		else
			stack->front->l_link = NULL;
	}
	stack->front = node->r_link;
	node->r_link = NULL;
	stack->count--;
	return (node);
}

// Rear 제거 : rear는 이전 노드를 가리키고 마지막 노드 연결 끊음
t_node	*ps_delete_rear(t_stack* stack)
{
	t_node	*node;

	node = ps_peek_rear(stack);
	if (node != NULL)
	{
		if (stack->count == 1)
			stack->front = NULL;
		else
			stack->rear->r_link = NULL;
	}
	stack->rear = node->l_link;
	node->l_link = NULL;
	stack->count--;
	return (node);
}

void	ps_delete_stack(t_stack* stack)
{
	t_node	*del_node;
	t_node	*node;
	size_t	len;
	size_t	i;

	i = 0;
	len = stack->count;
	node = stack->front;
	while (i++ < len)
	{
		del_node = node;
		free(del_node);
		node->r_link;
	}
	free(stack);
}