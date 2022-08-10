/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_duplication.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 22:30:17 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/09 03:46:50 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ch_duplication(t_ps *a)
{
	int		i;
	int		j;
	t_node	*buf;
	t_node	*node;

	i = a->count;
	buf = a->head;
	while (i--)
	{
		j = i;
		node = buf->next;
		while (j--)
		{
			if (buf->data == node->data)
				ps_error(2);
			node = node->next;
		}
		buf = buf->next;
	}	
}
