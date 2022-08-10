/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 03:37:31 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/09 03:38:33 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ch_read(char *line, t_ps *a, t_ps *b)
{
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break;
		checker(line, a, b);
		free(line);
	}
}
