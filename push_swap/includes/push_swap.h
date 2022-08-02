/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:28:57 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/02 16:16:26 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

# define TRUE		1
# define FALSE		0
# define LONG_MAX 	9223372036854775807

typedef struct s_node
{
	int				data;
	struct s_node	*r_link;
	struct s_node	*l_link;
}				t_node;

typedef struct s_stack
{
	int		count;
	t_node	*front;
	t_node	*rear;
}			t_stack;

t_stack	*ps_create_stack(void);
t_node	*ps_create_node(int data);
int		ps_insert_front(t_stack *stack, t_node element);
int		ps_insert_rear(t_stack *stack, t_node element);
t_node	*ps_delete_front(t_stack *stack);
t_node	*ps_delete_rear(t_stack *stack);
t_node	*ps_peek_front(t_stack *stack);
t_node	*ps_peek_rear(t_stack *stack);
void	ps_delete_stack(t_stack *stack);
int		ps_is_empty(t_stack *stack);
void	ps_display(t_stack *stack);

#endif