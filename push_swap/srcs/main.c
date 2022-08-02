/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:33:47 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/02 16:30:34 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char *av[])
{
	int		i;
	t_stack	*a;
	t_stack	*b;

	i = 0;
	if (ac <= 2)
		return (0);
	a = ps_create_stack();
	b = ps_create_stack();
	while (i < ac)
		ps_parsing(av[++i], a);
	ps_delete_stack(a);
	ps_delete_stack(b);
	return (0);
}
