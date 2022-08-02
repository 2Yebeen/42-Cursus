/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:53:41 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/02 16:21:02 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ps_create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	return (stack);
}

t_node	*ps_create_node(int data)
{
	t_node	*new_node;

	new_node = (t_node *)calloc(1, sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	return (new_node);
}

int	ps_insert_front(t_stack *stack, t_node element)
{
	t_node	*node;

	node = ps_create_node(element.data);
	if (!stack || !stack)
		return (FALSE);
	if (ps_is_empty(stack) == TRUE)
	{
		stack->front = node;
		stack->rear = node;
	}
	else
	{
		stack->front->l_link = node;
		node->r_link = stack->front;
		stack->front = node;
	}
	stack->count++;
	return (TRUE);
}

int	ps_insert_rear(t_stack *stack, t_node element)
{
	t_node	*node;

	node = ps_create_node(element.data);
	if (!stack || !stack)
		return (FALSE);
	if (ps_is_empty(stack) == TRUE)
	{
		stack->front = node;
		stack->rear = node;
	}
	else
	{
		stack->rear->r_link = node;
		node->l_link = stack->rear;
		stack->rear = node;
	}
	stack->count++;
	return (TRUE);
}
