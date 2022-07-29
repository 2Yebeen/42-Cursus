/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:55:47 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/30 01:59:06 by yeblee           ###   ########.fr       */
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
		a = ft_create_stack(a);
		b = ft_create_stack(b);
		while (i < ac)
			ft_parsing(av[i++], a);
		// ft_push(b, a);
		ft_delete(a);
		ft_delete(b);
	}
	system("leaks push_swap");
	return (0);
}
