/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 23:17:10 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/02 23:55:49 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_ps    *ps_create(void)
{
    t_ps    *ps;

    ps = (t_ps *)ft_calloc(1, sizeof(t_ps));
    return (ps);
}

int ps_add_data(t_ps *ps, int data)
{
    t_node  *buf;
    t_node  *new;

    new = (t_node *)ft_calloc(1, sizeof(t_node));
    if (!new)
        return (FALSE);
    new->data = data;
    if (ps->count == 0)
        ps->head = new;
    else
    {
        buf = ps_get_node(ps, ps->count - 1);
        buf->next = new;
        new->prev = buf;
    }
    ps->count += 1;
    return (TRUE);
}

t_node  *ps_get_node(t_ps *ps, int position)
{
    t_node  *buf;

    buf = ps->head;
    while (position--)
        buf = buf->next;
    return (buf);
}