/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 01:49:57 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/05 21:26:47 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*ps_array_validation(t_ps *ps)
{
	int	len;
	int	sorted;
	int	*array;

	len = ps->count;
	array = ps_array_add(ps);
	if (!array)
		ps_error(2);
	sorted = ps_array_sort(array, len);
	if (!sorted)
		ps_error(1);
	else if (sorted == -1)
		ps_error(0);
	return (array);
}

int	*ps_array_add(t_ps *ps)
{
	int		i;
	int		*array;
	t_node	*buf;

	i = 0;
	buf = ps->head;
	array = (int *)ft_calloc(ps->count, sizeof(int));
	if (!array)
		return (FALSE);
	while (i < ps->count)
	{
		array[i++] = buf->data;
		buf = buf->next;
	}
	return (array);
}

int	ps_array_sort(int *arr, int len)
{
	int	n;
	int	i;
	int	tmp;
	int	cnt;

	n = 0;
	cnt = -1;
	while (n < len)
	{
		i = 0;
		while (++i < len)
		{
			if (arr[i - 1] > arr[i])
			{
				tmp = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = tmp;
				cnt += 2;
			}
		}
		if (arr[n] == arr[n + 1])
			return (FALSE);
		n++;
	}
	return (cnt);
}
