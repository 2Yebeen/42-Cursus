/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 22:48:23 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/24 22:53:36 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int ft_error(char *reason, int fd)
{
	if (reason)
		ft_putstr_fd(reason, fd);
	ft_putstr_fd("USAGE : ", 1);
	ft_putstr_fd("./fractol Mandelbrot | Julia | BurningShip\n", 1);
	ft_putstr_fd("KEY :\n", 1);
	ft_putstr_fd("\t[W|A|S|D] / [↑|←|↓|→]     -> Move\n", 1);
	ft_putstr_fd("\t[ESC]                     -> Exit\n", 1);
	ft_putstr_fd("MOUSE :\n", 1);
	ft_putstr_fd("\t[SCROLL]                  -> Zoom\n", 1);
	exit(fd);
}

void	ft_draw_fractal(t_fractol *f)
{	
	while (f->c.y < WIN_HEIGHT && (f->c.x = -1) == -1)
	{
		while (f->c.x < WIN_WIDTH)
		{
			if (f->type.set == 1)
				ft_mandelbrot(f);
			else if (f->type.set == 2)
				ft_julia(f);
			else if (f->type.set == 3)
				ft_burningship(f);
			f->c.x += 1;
		}
		f->c.y += 1;
	}
}

void    ft_fractol(t_fractol *f)
{
	f->c.x = -2.60;
	f->c.y = -1.20;
	f->c.scale = 300.0;
	f->c.interation = 42;
	f->color.r = 4;
	f->color.g = 6;
	f->color.b = 15;
	f->mouse.x = WIN_WIDTH / 2;
	f->mouse.y = WIN_HEIGHT / 2;
	if (f->type.set == 2)
	{
		f->c.x = -2.10;
		f->c.interation = 100;
	}
	if (f->type.set == 3)
		f->c.interation = 250;
}

void    ft_init(t_fractol *f)
{
	ft_fractol(f);
	f->mlx.init = mlx_init();
	f->mlx.win = mlx_new_window(f->mlx.init, WIN_WIDTH, WIN_HEIGHT, TITLE(f->type.title));
	f->mlx.img = mlx_new_image(f->mlx.init, WIN_WIDTH, WIN_HEIGHT);
	f->image.addr = mlx_get_data_addr(f->mlx.img, &f->image.bites_per_pixel, &f->image.line_length, &f->image.endian);
	ft_draw_fractal(f);
	mlx_put_image_to_window(f->mlx.init, f->mlx.win, f->mlx.img, 0, 0);
	mlx_key_hook(f->mlx.win, ft_key_hook, f);
	mlx_mouse_hook(f->mlx.win, ft_mouse_hook, f);
	mlx_loop(f->mlx.init);
	exit(0);
}

int ft_check_type(t_fractol *f, int ac, char *av[])
{
	f->type.set = 0;
	f->type.title = av[1];
	if (ft_strcmp(av[1], "Mandelbrot")==0 && ac == 2)
		f->type.set = 1;
	//줄리아의 경우 입력 2개 더 받는 것 검증 필요
	else if (ft_strcmp(av[1], "Julia")==0 && ac == 4)
		f->type.set = 2;
	else if (ft_strcmp(av[1], "BurningShip")==0 && ac == 2)
		f->type.set = 3;
	return (f->type.set);
}


