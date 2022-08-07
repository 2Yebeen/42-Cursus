/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 21:10:06 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/05 21:18:17 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_delete_node(t_ps *ps)
{
	t_node	*buf;
	t_node	*del;

	buf = ps->head;
	while (buf->next)
	{
		del = buf;
		free(del);
		del = NULL;
		buf = buf->next;
	}
	free(buf);
	buf = NULL;
}

void	ps_destroy(t_ps *ps)
{
	if (ps->head)
		ps_delete_node(ps);
	free(ps);
	ps = NULL;
}
