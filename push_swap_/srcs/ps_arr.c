/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_arr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:48:34 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/03 10:48:53 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int *ps_add_arr(int len)
{
    int i;
    int *ret;
    t_node buf;
    
    ret = (int *)ft_calloc(len, sizeof(int));
    if (!ret)
        return (FALSE);
    buf = ps->head;
    while (i < len)
    {
        ret[i] = buf->data;
        buf = buf->next;
        i++;
    }
    return (ret);
}

int ps_sorting_arr(int *arr, int len)
{
    int n;
    int i;
    int j;
    int tmp;
    
    n = 0;
    while (n++ < len)
    {
        i = 0
        j = 1
        while (j < len)
        {
            if (arr[i] > arr[j])
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                i++;
                j++;
            }
            if (arr[i] == arr[j])
                return (FALSE);
        }
    }
    return (TRUE);
}

int *ps_arr(t_ps *ps)
{
    int     len;
    int     *ret;
    
    len = ps->count
    ret = ps_add_arr(len);
    if (!ret)
        ps_error(2);
    if (!ps_sorting_arr(ret, len))
        ps_error(2);
    return (ret);
}