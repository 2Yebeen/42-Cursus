/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:51:11 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/27 14:20:18 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_error(char *msg, int fd)
{
	if (msg)
		ft_putstr_fd(msg, fd);
	ft_putstr_fd("\n\e[33m", 1);
	ft_putstr_fd("//////////////////////////////////////////////////////\n", 1);
	ft_putstr_fd("//                     FRACT'OL                     //\n", 1);
	ft_putstr_fd("//////////////////////////////////////////////////////\n", 1);
	ft_putstr_fd(" USAGE : ", 1);
	ft_putstr_fd("./fractol <type>\n", 1);
	ft_putstr_fd(" TYPE\n", 1);
	ft_putstr_fd("\t1) Mandelbrot\n", 1);
	ft_putstr_fd("\t2) Julia -0.7 -0.27015\n", 1);
	ft_putstr_fd("\t3) BurningShip\n", 1);
	ft_putstr_fd(" KEY\n", 1);
	ft_putstr_fd("\t[W|A|S|D] or [↑|←|↓|→] -> Move\n", 1);
	ft_putstr_fd("\t[ESC]                  -> Exit\n", 1);
	ft_putstr_fd(" MOUSE\n", 1);
	ft_putstr_fd("\t[SCROLL]               -> Zoom\n", 1);
	ft_putstr_fd("\t[LEFT_BUTTON]          -> Change Color\n", 1);
	ft_putstr_fd("//////////////////////////////////////////////////////\n\n", 1);
	return (fd);
}

int	ft_check_type(t_fractol *f, int ac, char *av[])
{
	f->set = 0;
	if (ac >= 2)
	{
		f->title = av[1];
		if (ft_strcmp(av[1], "Mandelbrot") == 0)
			f->set = 1;
		else if (ft_strcmp(av[1], "Julia") == 0 && ac == 4)
		{
			f->set = 2;
			f->julia.x = ft_atof(av[2]);
			f->julia.y = ft_atof(av[3]);
		}
		else if (ft_strcmp(av[1], "BurningShip") == 0)
			f->set = 3;
	}
	if (f->set == 0)
		ft_error(NULL, 2);
	return (f->set);
}
