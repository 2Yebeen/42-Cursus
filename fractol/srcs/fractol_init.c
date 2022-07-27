/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:10:19 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/27 14:20:36 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_fractal_init(t_fractol *f)
{
	f->color = 0x00F0F8FF;
	f->zoom = 0.03;
	if (f->set == 1)
	{
		f->x_max = 1.5;
		f->x_min = -2.5 ;
		f->y_max = 2.0 ;
		f->y_min = -2.0 ;
	}
	else
	{
		f->x_max = 2.0;
		f->x_min = -2.0 ;
		f->y_max = 2.0 ;
		f->y_min = -2.0 ;
	}
}

int	ft_mlx_init(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		return (0);
	f->win = mlx_new_window(f->mlx, WIN_WIDTH, WIN_HEIGHT, TITLE(f->title));
	if (!f->win)
		return (0);
	f->img = (t_image *)malloc(sizeof(t_image));
	if (!f->img)
		return (0);
	ft_fractal_init(f);
	mlx_key_hook(f->win, ft_key_hook, f);
	mlx_mouse_hook(f->win, ft_mouse_hook, f);
	return (1);
}

void	ft_image_init(t_fractol *f)
{
	f->img->ptr = mlx_new_image(f->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!f->img->ptr)
		exit(1);
	f->img->buff = (int *)mlx_get_data_addr(f->img->ptr, \
		&f->img->bits_per_pixel, &f->img->line_length, &f->img->endian);
	if (!f->img->buff)
		exit(1);
}
