/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:08:14 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/26 23:16:20 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_draw(t_fractol *f)
{
	int	x;
	int	y;

	x = 0;
	ft_image_init(f);
	while (x < WIN_WIDTH)
	{
		y = 0;
		f->c.x = f->x_min + x * ((f->x_max - f->x_min) / WIN_WIDTH);
		while (y < WIN_HEIGHT)
		{
			f->c.y = f->y_min + y * ((f->y_max - f->y_min) / WIN_HEIGHT);
			if (f->set == 1)
				ft_mandelbrot(f->c, f);
			else if (f->set == 2)
				ft_julia(f->c, f);
			else if (f->set == 3)
				ft_mandelbrot(f->c, f);
			y++;
			ft_color_pixel(f, x, y);
		}
		x++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img->ptr, 0, 0);
	mlx_destroy_image(f->mlx, f->img->ptr);
}

void	ft_color_pixel(t_fractol *f, int x, int y)
{
	int	pixel;
	int	color;

	color = 0;
	if (f->i != ITERATION)
		color = 1;
	pixel = (y * 1000 + x);
	f->img->buff[pixel] = ((f->i * f->color) + 0x008DE3EC) * color;
}
