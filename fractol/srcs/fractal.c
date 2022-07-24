/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 22:49:25 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/24 22:53:42 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_mandelbrot(t_fractol *f)
{
	int		i;
	double 	zx;
	double 	zy;
	double 	tmp;
	double 	cx;
	double 	cy;
	
	i = 0;
	// zx = (f->mouse.x - WIN_WIDTH) / ((double)WIN_WIDTH * 2) + 0.25;
	// zy = (f->mouse.y - WIN_HEIGHT) / ((double)WIN_HEIGHT) + 0.05;
	zx = 0;
	zy = 0;
	cx = f->c.x / f->c.scale + f->c.y;
	cy = f->c.y / f->c.scale + f->c.x;
	while (i < f->c.interation && pow(zx, 2) + pow(zy, 2) < 4)
	{
		tmp = pow(zx, 2) - pow(zy, 2) + cx;
		zy = (2 * zx * zy) + cy;
		zx = tmp;
		i++;
	}
}

void	ft_julia(t_fractol *f)
{
	int		i;
	double 	zx;
	double 	zy;
	double 	tmp;
	double 	cx;
	double 	cy;
	
	i = 0;
	// zx = (f->mouse.x - WIN_WIDTH) / ((double)WIN_WIDTH * 2) + 0.25;
	// zy = (f->mouse.y - WIN_HEIGHT) / ((double)WIN_HEIGHT) + 0.05;
	zx = 0;
	zy = 0;
	cx = f->c.x / f->c.scale + f->c.y;
	cy = f->c.y / f->c.scale + f->c.x;
	while (i < f->c.interation && pow(zx, 2) + pow(zy, 2) < 4)
	{
		tmp = pow(zx, 2) - pow(zy, 2) + cx;
		zy = (2 * zx * zy) + cy;
		zx = tmp;
		i++;
	}
}
void	ft_burningship(t_fractol *f)
{
	int		i;
	double 	zx;
	double 	zy;
	double 	tmp;
	double 	cx;
	double 	cy;
	
	i = 0;
	// zx = (f->mouse.x - WIN_WIDTH) / ((double)WIN_WIDTH * 2) + 0.25;
	// zy = (f->mouse.y - WIN_HEIGHT) / ((double)WIN_HEIGHT) + 0.05;
	zx = 0;
	zy = 0;
	cx = f->c.x / f->c.scale + f->c.y;
	cy = f->c.y / f->c.scale + f->c.x;
	while (i < f->c.interation && pow(zx, 2) + pow(zy, 2) < 4)
	{
		tmp = pow(zx, 2) - pow(zy, 2) + cx;
		zy = (2 * zx * zy) + cy;
		zx = tmp;
		i++;
	}
}