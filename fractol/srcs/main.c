/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:23:54 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/26 04:03:08 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int ac, char *av[])
{
	t_fractol f;

	if (ft_check_type(&f, ac, av))
	{
		if (!ft_mlx_init(&f, &f.img))
		{
			ft_error("\nERROR : SOMETHING WRONG WITH MLX, TRY AGAIN\n", 2);
			exit(1);
		}
		ft_fractal_init(&f);
		ft_draw(&f);
		
	}
	return (0);
}