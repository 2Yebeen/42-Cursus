/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 23:43:03 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/03 00:28:50 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    ps_swap(t_ps *ps, int type)
{
    int     data;
    
    if (ps->count < 2)
        return ;
    data = ps->head->data;
    ps->head->data = ps->head->next->data;
    ps->head->next->data = data;
    ps_display(type);
}
