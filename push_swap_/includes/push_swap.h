/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 22:38:30 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/03 00:02:17 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SA 11
# define SB 12
# define SS 13

# define PA 21
# define PB 22

# define RA 31
# define RB 32
# define RR 33

# define RRA 41
# define RRB 42
# define RRR 43

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_ps
{
	int		count;
	t_node	*head;
}			t_ps;

#endif