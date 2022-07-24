/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 22:50:18 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/24 22:53:39 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_key_hook(int keycode, t_fractol *f)
{
	if (keycode == ECS)
		exit(0);
	else if (keycode == KEY_W || keycode == KEY_UP)
		f->c.y -= 10 / f->c.scale;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		f->c.x -= 10 / f->c.scale;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		f->c.y += 10 / f->c.scale;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		f->c.x += 10 / f->c.scale;
	mlx_destroy_image(f->mlx.init, f->mlx.img);
	mlx_clear_window(f->mlx.init, f->mlx.win);
	return 0;
}

void	ft_change_color(t_fractol *f)
{
	f->color.r = rand() % (0x7F + 0x01);
	f->color.g = rand() % (0x7F + 0x01);
	f->color.b = rand() % (0x7F + 0x01);
}


void	ft_zoom_in(int x, int y, t_fractol *f)
{
	if (f->c.scale >= MAX_SCALE)
	{
		f->c.scale = MAX_SCALE;
		f->color.r++;
		return;
	}
	f->c.x = (x / f->c.scale + f->c.x) - ((f->c.scale * SCALE_PRECISION) / 2);
	f->c.x += ((f->c.scale * SCALE_PRECISION) / 2) - (x / (f->c.scale * SCALE_PRECISION));
	f->c.y = (y / f->c.scale + f->c.y) - ((f->c.scale * SCALE_PRECISION) / 2);
	f->c.y += ((f->c.scale * SCALE_PRECISION) / 2) - (y / (f->c.scale * SCALE_PRECISION));
	f->c.scale *= SCALE_PRECISION;
	f->color.r++;
}

void	ft_zoom_out(t_fractol *f)
{
	f->c.x = (f->mouse.x / f->c.scale + f->c.x) - ((f->c.scale / SCALE_PRECISION) / 2);
	f->c.x += ((f->c.scale / SCALE_PRECISION) / 2) - (f->mouse.x / (f->c.scale / SCALE_PRECISION));
	f->c.y = (f->mouse.y / f->c.scale + f->c.y) - ((f->c.scale / SCALE_PRECISION) / 2);
	f->c.y += ((f->c.scale / SCALE_PRECISION) / 2) - (f->mouse.y / (f->c.scale / SCALE_PRECISION));
	f->c.scale /= SCALE_PRECISION;
	f->color.r--;
}

int	ft_mouse_hook(int mousecode, int x, int y, t_fractol *f)
{
	if (x > 0 && y > 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
	{
		if (mousecode == MOUSE_UP_SCRLL)
		{
			printf("%d, %d\n",x, y);
			ft_zoom_in(x, y, f);
		}
		else if (mousecode == MOUSE_DOWN_SCRLL)
		{
			printf("%d, %d\n",x, y);
			ft_zoom_out(f);
		}
		else if (mousecode == MOUSE_RIGHT_CLK)
			ft_change_color(f);
	mlx_destroy_image(f->mlx.init, f->mlx.img);
	mlx_clear_window(f->mlx.init, f->mlx.win);
	}
	return (0);
}