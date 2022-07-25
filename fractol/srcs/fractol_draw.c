/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:08:14 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/26 04:31:15 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_event_hook(t_fractol *f)
{
	mlx_key_hook(f->win, ft_key_hook, &f);
	mlx_mouse_hook(f->win, ft_mouse_hook, &f);
	mlx_loop(f->mlx);
}

void    ft_draw(t_fractol *f)
{
    int	x;
    int	y;

	mlx_clear_window(f->mlx, f->win);
    y = 0;
    while (y < WIN_HEIGHT)
    {
        x = 0;
        while (x < WIN_WIDTH)
        {
			f->i = 0;
			if (f->set == 1 || f->set == 3)
			{				
				f->c.y = f->y_max - y * ((f->y_max - f->y_min) / WIN_HEIGHT);
				f->c.x = f->x_min + x * ((f->x_max - f->x_min) / WIN_WIDTH);
			}
			if (f->set == 1)
				ft_mandelbrot(f->c, f);
			else if(f->set == 2)
				ft_julia(f->c, f);
			else if (f->set == 3)
				ft_mandelbrot(f->c, f);
			x++;
			ft_color_pixel(f, x, y);
        }
		y++;
    }
	mlx_put_image_to_window(f->mlx, f->win, f->img.ptr, 0, 0);
	ft_event_hook(f);
}

void	ft_color_pixel(t_fractol *f, int x, int y)
{
	int	pixel;
	int color;

	color = 0;
	if (f->i != INFINITY)
		color = 1;
	pixel = (y * 1000 + x);
	f->img.buff[pixel + 0] = ((f->i * f->color) + 0x008DE3EC) * color;
	f->img.buff[pixel + 1] = ((f->i * f->color) + 0x008DE3EC) * color;
	f->img.buff[pixel + 2] = ((f->i * f->color) + 0x008DE3EC) * color;
	f->img.buff[pixel + 3] = 0;
}