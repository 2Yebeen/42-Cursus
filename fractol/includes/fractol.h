/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:23:45 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/26 04:31:03 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define TITLE(title)	title
# define WIN_WIDTH 		1000
# define WIN_HEIGHT 	1000
# define ITERATION		250

# define ESC			53
# define ENTER			36
# define KEY_W        	13
# define KEY_A        	0
# define KEY_S        	1
# define KEY_D        	2
# define KEY_UP			126
# define KEY_DOWN		125
# define KEY_LEFT		123
# define KEY_RIGHT		124

typedef struct	s_complex
{
	double	x;
	double	y;
}				t_complex;

typedef struct	s_image
{
	void	*ptr;
	int		*buff;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct	s_fractol
{
	void    	*mlx;
	void    	*win;
	char    	*title;
	t_complex	c;
	double		x_max;
	double		x_min;
	double		y_max;
	double		y_min;
	double		zoom;
	int			color;
	int 		set;
	int			i;
	t_image		img;
	t_complex	mouse;	
	t_complex	julia;
}				t_fractol;

int	ft_check_type(t_fractol *f, int ac, char *av[]);
int	ft_mlx_init(t_fractol *f, t_image *img);
int ft_error(char *msg, int fd);
void    ft_fractal_init(t_fractol *f);
void    ft_draw(t_fractol *f);
void	ft_mandelbrot(t_complex c, t_fractol *f);
void	ft_julia(t_complex c, t_fractol *f);
void	ft_color_pixel(t_fractol *f, int x, int y);
void	ft_event_hook(t_fractol *f);
int ft_key_hook(int keycode, t_fractol *f);
int ft_mouse_hook(int button, int x, int y, t_fractol *f);

#endif