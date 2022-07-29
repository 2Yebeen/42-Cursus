/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:55:47 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/29 17:35:17 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	ft_clear(t_stack *stack)
{
	t_node	*clear;
	t_node	*next;

	clear = stack->header.r_link;
	while (stack->count)
	{
		next = clear->r_link;
		clear->data = 0x00;
		clear->l_link = NULL;
		clear->r_link = NULL;
		free(clear);
		stack->count -= 1;
		clear = next;
	}
	clear = NULL;
	next = NULL;
}

void	ft_delete(t_stack *stack)
{
	ft_clear(stack);
	stack->header.r_link = NULL;
	stack->header.l_link = NULL;
	stack->count = 0;
	free(stack);
	stack = NULL;
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

void	ft_error(char *msg, int fd)
{
	if (msg)
		ft_putstr_fd(msg, fd);
	exit(0);
}

t_stack	*ft_create_stack(t_stack *stack)
{
	t_stack	*new;

	new = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!new)
		ft_error("ft_create_stack중 할당에 실패했습니다.\n", 2);
	return (new);
}

t_node	*ft_get_node(t_stack *stack, int position)
{
	t_node	*buf;

	buf = stack->header.r_link;
	while (position)
	{
		buf = buf->r_link;
		position -= 1;
	}
	return (buf);
}

int	ft_add_data(t_stack *stack, int data)
{
	t_node	*buf;
	t_node	*new;

	new = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!new)
		return (FALSE);
	new->data = data;
	if ((stack->count) == 0)
	{
		stack->header.r_link = new;
		new->l_link = new;
		new->r_link = new;
	}
	else
	{
		buf = ft_get_node(stack, stack->count - 1);
		new->l_link = buf;
		new->r_link = buf->r_link;
		buf->r_link->l_link = new;
		buf->r_link = new;
	}
	stack->count += 1;
	return (TRUE);
}


void	ft_parsing(char *str, t_stack *stack)
{
	int		idx;
	char	**tmp;

	idx = 0;
	tmp = ft_split(str, ' ');
	while (tmp[idx])
	{
		ft_add_data(stack, ft_atoi(tmp[idx]));
		idx++;
	}
}

int	main(int ac, char *av[])
{
	int		i;
	t_stack	*a;
	t_stack	*b;

	i = 0;
	if (ac > 2)
	{
		a = ft_create_stack(a);
		b = ft_create_stack(b);
		while (av[++i])
			ft_parsing(av[i], a);
	}
	ft_display(a);
	ft_display(b);
	ft_delete(a);
	ft_delete(b);
	system("leaks push_swap");
	return (0);
}
