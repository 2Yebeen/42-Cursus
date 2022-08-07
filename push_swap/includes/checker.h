/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 21:50:11 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/08 00:07:38 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "push_swap.h"

int		ch_is_sorted(t_ps *a);
void	checker(char *line, t_ps *a, t_ps *b);
int		ch_command(char *line, int l);

#endif