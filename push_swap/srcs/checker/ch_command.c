/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 23:52:28 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/07 23:52:48 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	ch_command(char *line, int l)
{
	if ( ft_strncmp(line, "pa", l) == 0 || ft_strncmp(line, "pb", l) == 0
		|| ft_strncmp(line, "sa", l) == 0
		|| ft_strncmp(line, "sb", l) == 0 || ft_strncmp(line, "ss", l) == 0
		|| ft_strncmp(line, "ra", l) == 0
		|| ft_strncmp(line, "rb", l) == 0 || ft_strncmp(line, "rr", l) == 0
		|| ft_strncmp(line, "rra", 3) == 0
		|| ft_strncmp(line, "rrb", l) == 0 || ft_strncmp(line, "rrr", l) == 0
	)
		return (TRUE);
	else
		return (FALSE);
}
