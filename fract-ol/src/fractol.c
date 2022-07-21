/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:03:06 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/21 17:16:29 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

#define MAX_ITERATION 250
#define WHITE 0xFFFFFF
#define BLACK 0x000000

typedef struct s_image
{
    void     *img;
    int     *data;
    int      bpp;
    int      size_line;
    int        endian;
}               t_image;

typedef struct      s_complex
{
    double r;
    double i;
}                   t_complex;

int ft_close(int keycode)
{
    if (keycode == 53)
        exit(0);
    return 0;
}

int mandelbrot(double a, double b)
{
    int i;
    double zx;
    double zy;
    double tmp;
    double cr;
    double ci;

    i = 0;
    zx = 0;
    zy = 0;
    cr = ((a - 1000 / 2) * 2.0 / 1000) - 0.5;
    ci = ((1000 / 2) - b) * 2.0 / 1000;
    while (i < MAX_ITERATION)
    {
        tmp = (zx * zx) - (zy * zy) + cr;
        zy = (2 * zx * zy) + ci;
        zx = tmp;
        i++;
        if ((zx * zx) + (zy * zy) > 4)
            return (WHITE);
    }
    return (BLACK);
}

int julia(double a, double b)
{
    int i;
    double zx;
    double zy;
    double tmp;
    double cr;
    double ci;

    i = 0;
    cr = -0.629578;
    ci = -0.41524;
    zx = ((a - 1000 / 2) * 2.0 / 1000);
    zy = ((1000 / 2) - b) * 2.0 / 1000;
    while (i < MAX_ITERATION)
    {
        tmp = (zx * zx) - (zy * zy) + cr;
        zy = (2 * zx * zy) + ci;
        zx = tmp;
        i++;
        if ((zx * zx) + (zy * zy) > 4)
            return (WHITE);
    }
    return (BLACK);
}

int main(void)
{
    int     i;
    int     j;
    void    *mlx;
    void    *window;
    t_image   img;
    t_complex c;

    mlx = mlx_init();
    window = mlx_new_window(mlx, 1000, 1000, "My-First-Fract'ol");
    mlx_key_hook(window, ft_close, NULL);
    img.img = mlx_new_image(mlx, 1000, 1000);
    img.data = (int *)mlx_get_data_addr(img.img, &img.bpp, &img.size_line, &img.endian);
    i = 0;
    while (i < 1000)
    {
        c.i = i;
        j = 0;
        while (j < 1000)
        {
            c.r = j;
            img.data[i * 1000 + j] = julia(c.r, c.i);
            j++;
        }
        i++;
    }
    mlx_put_image_to_window(mlx, window, img.img, 0, 0);
    mlx_loop(mlx);
    
    return 0;
}