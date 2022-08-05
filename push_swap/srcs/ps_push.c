/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:46:18 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/05 13:14:25 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_push(t_ps *a, t_ps *b, int type)
{
	t_node	*node;

	if (a->count)
	{		
		node = ps_left_pop(a);
		ps_left_add(b, node->data);
		ps_display(type);
		free(node);
		node = NULL;
	}
}
