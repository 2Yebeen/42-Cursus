/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 22:59:32 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/30 11:19:11 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_error(char *msg, int fd)
{
	if (msg)
		ft_putstr_fd(msg, fd);
	exit(0);
}

void	ps_display(t_stack *stack)
{
	int		i;
	t_node	*buf;

	i = 0;
	buf = stack->header.r_link;
	ft_printf("--------------------------\n");
	while (i < stack->count)
	{
		ft_printf("stack[%d] = ", i++);
		ft_printf("%d\n", buf->data);
		// printf("\nstack[%d] = %d\n", i++, buf->data);
		buf = buf->r_link;
	}
	ft_printf("--------------------------\n");
}

void	ps_parsing(const char *str, t_stack *stack)
{
	int		idx;
	char	**tmp;

	idx = 0;
	tmp = ft_split(str, ' ');
	while (tmp[idx])
	{
		ps_add_data(stack, ps_atoi(tmp[idx]));
		free(tmp[idx]);
		tmp[idx] = NULL;
		idx++;
	}
	free(tmp);
	tmp = NULL;
}