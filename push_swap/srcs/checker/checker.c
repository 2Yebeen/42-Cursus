/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 22:30:17 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/09 03:46:50 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	checker(char *line, t_ps *a, t_ps *b)
{
	int	l;

	l = ft_strlen(line) - 1;
	if (!ch_command(line, l))
		ps_error(2);
	if (ft_strncmp(line, "sa", l) == 0 || ft_strncmp(line, "ss", l) == 0)
		ps_swap(a, NONE);
	if (ft_strncmp(line, "sb", l) == 0 || ft_strncmp(line, "ss", l) == 0)
		ps_swap(b, NONE);
	if (ft_strncmp(line, "pa", l) == 0)
		ps_push(b, a, NONE);
	if (ft_strncmp(line, "pb", l) == 0)
		ps_push(a, b, NONE);
	if (ft_strncmp(line, "ra", l) == 0 || ft_strncmp(line, "rr", l) == 0)
		ps_rotate(a, NONE);
	if (ft_strncmp(line, "rb", l) == 0 || ft_strncmp(line, "rr", l) == 0)
		ps_rotate(b, NONE);
	if (ft_strncmp(line, "rra", l) == 0 || ft_strncmp(line, "rrr", l) == 0)
		ps_reverse_rotate(a, NONE);
	if (ft_strncmp(line, "rrb", l) == 0 || ft_strncmp(line, "rrr", l) == 0)
		ps_reverse_rotate(b, NONE);
}
void	ch_duplication(t_ps *a)
{
	int		i;
	int		j;
	t_node	*buf;
	t_node	*node;
	
	i = a->count;
	buf = a->head;
	while (i--)
	{
		j = i;
		node = buf->next;
		while (j--)
		{
			if (buf->data == node->data)
				ps_error(2);
			node = node->next;
		}
		buf = buf->next;
	}	
}

int	main(int ac, char *av[])
{
	int		i;
	t_ps	*a;
	t_ps	*b;
	char	*line;
		
	i = 0;
	if (ac >= 2)
	{
		a = ps_create();
		b = ps_create();
		while (++i < ac)
			ps_parsing(av[i], a);
		ch_duplication(a);
		ch_read(line, a, b);
		if (ch_is_sorted(a) && !b->count)
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
		ps_destroy(a);
		ps_destroy(b);
	}
	return (0);
}
