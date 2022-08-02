/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:18:54 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/02 16:20:42 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*ps_peek_front(t_stack *stack)
{
	return (stack->front);
}

t_node	*ps_peek_rear(t_stack *stack)
{
	return (stack->rear);
}

int	ps_is_empty(t_stack *stack)
{
	if (stack->count == 0)
		return (TRUE);
	else
		return (FALSE);
}

void	ps_display(t_stack *stack)
{
	size_t	len;
	t_node	*node;
	size_t	i;

	i = 0;
	len = stack->count;
	node = stack->front;
	printf("current count : %ld\n", len);
	while (i++ < len)
	{
		printf("Deque[%ld] = %c\n", i, node->data);
		node = node->r_link;
	}
	free(node);
}
