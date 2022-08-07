/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 01:39:08 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/05 01:45:42 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_parsing(const char *str, t_ps *a)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = ft_split(str, ' ');
	if (!tmp[i])
		ps_error(2);
	while (tmp[i])
	{
		if (!ps_right_add(a, ps_atoi(tmp[i])))
			ps_error(2);
		free(tmp[i]);
		tmp[i] = NULL;
		i++;
	}
	free(tmp);
	tmp = NULL;
}
