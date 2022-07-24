/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:30:46 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/24 22:53:13 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int main(int ac, char *av[])
{
	t_fractol   *f;
	
	if (!(f = (t_fractol *)malloc(sizeof(t_fractol))))
		return (ft_error("Malloc failed", 2));
	if (ac >= 2)
	{
		if (!ft_check_type(f, ac, av))
			return (ft_error("Please try again", 2));
	}
	else
		return (ft_error(NULL, 2));
	ft_init(f);
	return (0);
}