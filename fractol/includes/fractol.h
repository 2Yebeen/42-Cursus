/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:23:45 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/27 11:26:33 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "keycode.h"
# include "types.h"

# define TITLE(title)	title
# define WIN_WIDTH 		1000
# define WIN_HEIGHT 	1000
# define ITERATION		250

int		ft_check_type(t_fractol *f, int ac, char *av[]);
int		ft_mlx_init(t_fractol *f);
int		ft_error(char *msg, int fd);
void	ft_image_init(t_fractol *f);
void	ft_fractal_init(t_fractol *f);
void	ft_draw(t_fractol *f);
void	ft_mandelbrot(t_complex c, t_fractol *f);
void	ft_julia(t_complex c, t_fractol *f);
void	ft_color_pixel(t_fractol *f, int x, int y);
int		ft_key_hook(int keycode, t_fractol *f);
int		ft_mouse_hook(int button, int x, int y, t_fractol *f);

#endif