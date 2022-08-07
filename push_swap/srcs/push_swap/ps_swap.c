/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:46:12 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/05 11:47:34 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_swap(t_ps *ps, int type)
{
	int	data;

	if (ps->count >= 2)
	{		
		data = ps->head->data;
		ps->head->data = ps->head->next->data;
		ps->head->next->data = data;
		ps_display(type);
	}
}
