/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:36:59 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/27 11:23:26 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

typedef struct s_image
{
	void	*ptr;
	int		*buff;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	char		*title;
	int			set;
	t_complex	c;
	t_image		*img;
	double		x_max;
	double		x_min;
	double		y_max;
	double		y_min;
	double		zoom;
	int			color;
	int			i;
	t_complex	julia;
}				t_fractol;

#endif