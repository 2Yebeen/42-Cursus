/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 23:27:30 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/27 14:25:57 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_key_move(int keycode, t_fractol *f)
{
	if (keycode == KEY_LEFT || keycode == KEY_A)
	{
		f->x_min = f->x_min + f->zoom;
		f->x_max = f->x_max + f->zoom;
		ft_draw(f);
	}
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
	{
		f->x_min = f->x_min - f->zoom;
		f->x_max = f->x_max - f->zoom;
		ft_draw(f);
	}
	else if (keycode == KEY_UP || keycode == KEY_W)
	{
		f->y_min = f->y_min + f->zoom;
		f->y_max = f->y_max + f->zoom;
		ft_draw(f);
	}
	else if (keycode == KEY_DOWN || keycode == KEY_S)
	{
		f->y_min = f->y_min - f->zoom;
		f->y_max = f->y_max - f->zoom;
		ft_draw(f);
	}
}

int	ft_key_hook(int keycode, t_fractol *f)
{
	if (keycode == KEY_ESC)
	{
		ft_putstr_fd("\e[35m[ EXIT ]\n", 1);
		free(f->img);
		exit(0);
	}
	else if (keycode == KEY_ENTER)
	{
		f->color += 123456;
		ft_draw(f);
	}
	else
		ft_key_move(keycode, f);
	return (1);
}

void	zoom(t_fractol *f, double x, double y, double zoom)
{
	double	xx;
	double	yy;

	xx = (((double)x / WIN_WIDTH) * (f->x_max - f->x_min)) + f->x_min;
	yy = (((double)y / WIN_HEIGHT) * (f->y_max - f->y_min)) + f->y_min;
	f->x_min = xx + ((f->x_min - xx) * zoom);
	f->y_min = yy + ((f->y_min - yy) * zoom);
	f->y_max = yy + ((f->y_max - yy) * zoom);
	f->x_max = xx + ((f->x_max - xx) * zoom);
}

int	ft_mouse_hook(int button, int x, int y, t_fractol *f)
{
	if (button == M_SCROLL_DOWN)
	{
		zoom(f, (double)x, (double)y, 1.3);
		f->zoom *= 1.3;
		ft_draw(f);
	}
	else if (button == M_SCROLL_UP)
	{
		zoom(f, (double)x, (double)y, 0.7);
		f->zoom *= 0.7;
		ft_draw(f);
	}
	else if (button == M_LEFT_BUTTON)
	{
		f->color -= 125356;
		ft_draw(f);
	}
	return (1);
}
