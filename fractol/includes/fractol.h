/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 10:07:47 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/24 23:07:18 by yeblee           ###   ########.fr       */
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
# include "type.h"
# include "event.h"

# define TITLE(fractal_set)	(fractal_set)
# define WIN_WIDTH          1920
# define WIN_HEIGHT         1080
# define MAX_SCALE			250000
# define SCALE_PRECISION	1.042

int		ft_check_type(t_fractol *f, int ac, char *av[]);
void    ft_init(t_fractol *f);
void    ft_fractol(t_fractol *f);
void	ft_draw_fractal(t_fractol *f);
int 	ft_error(char *reason, int fd);
int		ft_key_hook(int keycode, t_fractol *f);
void	ft_change_color(t_fractol *f);
void	ft_zoom_in(int x, int y, t_fractol *f);
void	ft_zoom_out(t_fractol *f);
int		ft_mouse_hook(int mousecode, int x, int y, t_fractol *f);
void	ft_mandelbrot(t_fractol *f);
void	ft_julia(t_fractol *f);
void	ft_burningship(t_fractol *f);

#endif
