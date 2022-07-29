/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 22:59:32 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/30 02:00:36 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(char *msg, int fd)
{
	if (msg)
		ft_putstr_fd(msg, fd);
	exit(0);
}

void	ft_display(t_stack *stack)
{
	int		i;
	t_node	*buf;

	i = 0;
	buf = stack->header.r_link;
	while (i < stack->count)
	{
		printf("stack[%d] = %d\n", i++, buf->data);
		buf = buf->r_link;
	}
}

void	ft_parsing(const char *str, t_stack *stack)
{
	int		idx;
	char	**tmp;

	idx = 0;
	tmp = ft_split(str, ' ');
	while (tmp[idx])
	{
		ft_add_data(stack, ft_atoi(tmp[idx]));
		free(tmp[idx]);
		tmp[idx] = NULL;
	}
	free(tmp);
	tmp = NULL;
}