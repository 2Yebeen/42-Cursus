/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 22:55:18 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/07 23:52:54 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	ch_is_sorted(t_ps *a)
{
	int	i;
	t_node	*node;
	
	i = 1;
	node = a->head;
	while (i < a->count)
	{
		if (node->data > node->next->data)
			return (FALSE);
		node = node->next;
		i++;
	}
	return (TRUE);
}
