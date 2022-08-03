/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 23:43:03 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/03 12:32:35 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_swap(t_ps *ps, int type)
{
	int	data;

	if (ps->count < 2)
		return ;
	data = ps->head->data;
	ps->head->data = ps->head->next->data;
	ps->head->next->data = data;
	ps_display(type);
}

void	ps_push(t_ps *a, t_ps *b, int type)
{
	//a : pop,b : add_top
}

void	ps_rotate(t_ps *ps, int type)
{
	//pop, add_bottom
}

void	ps_reverse_rotate(t_ps *ps, int type)
{
	//pop_bottom, add_top
}
