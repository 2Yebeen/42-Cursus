/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 01:26:21 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/26 03:08:47 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


void	ft_mandelbrot(t_complex c, t_fractol *f)
{
	t_complex	z;
	double		tmpx;
	double		tmpy;
	z.x = c.x;
	z.y = c.y;
	while (f->i < ITERATION && (z.x * z.x) + (z.y * z.y) < 4)
	{
		tmpx = (z.x * z.x) - (z.y * z.y);
		tmpy = (2 * z.x * z.y);
		if (f->set == 3 && tmpy < 0)
			tmpy = -tmpy;
		z.y = tmpy + c.y;
		z.x = tmpx + c.x;
		f->i++;
	}
}

void	ft_julia(t_complex c, t_fractol *f)
{
	t_complex	z;
	double		tmp;

	z.x = c.x;
	z.y = c.y;
	while (f->i < ITERATION && (z.x * z.x) + (z.y * z.y) < 4)
	{
		tmp = z.x;
		z.x = (z.x * z.x) - (z.y * z.y) + c.x;
		z.y = (2 * tmp * z.y) + c.y;
		f->i++;
	}
}
