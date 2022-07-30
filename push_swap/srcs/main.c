/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:55:47 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/30 11:23:00 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char *av[])
{
	int		i;
	t_stack	*a;
	t_stack	*b;

	i = 1;
	if (ac > 2)
	{
		a = ps_create_stack(a);
		b = ps_create_stack(b);
		while (i < ac)
			ps_parsing(av[i++], a);
		ps_push(b, a);
		ps_display(a);
		ps_display(b);
		ps_delete(a);
		ps_delete(b);
	}
	// system("leaks push_swap");
	return (0);
}
