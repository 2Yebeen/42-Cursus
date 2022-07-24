/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 22:56:48 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/24 23:03:22 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

typedef struct  s_color
{
	int r;
	int g;
	int b;
}               t_color;

typedef struct  s_mouse
{
	int x;
	int y;
}               t_mouse;

typedef struct  s_complex
{
	double x;
	double y;
	double scale;
	double interation;
}               t_complex;

typedef struct  s_mlx
{
	void    *init;
	void    *win;
	void    *img;
}               t_mlx;

typedef struct  s_type
{
	char    *title;
	int     set;    
}               t_type;

typedef struct  s_image
{
	char    *addr;
	int     bites_per_pixel;
	int     line_length;
	int     endian;
}               t_image;

typedef struct  s_fractol
{
	
	t_mlx       mlx;
	t_image     image;
	t_type      type;
	t_complex   c;
	t_color     color;
	t_mouse     mouse;
}               t_fractol;

#endif