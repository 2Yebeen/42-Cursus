/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:56:26 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/30 02:01:12 by yeblee           ###   ########.fr       */
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
	struct s_node	*l_link;
	struct s_node	*r_link;
}			t_node;

typedef struct s_stack
{
	int		count;	
	t_node	header;
}	t_stack;

t_stack	*ft_create_stack(t_stack *stack);
t_node	*ft_get_node(t_stack *stack, int position);
int		ft_add_data(t_stack *stack, int data);
void	ft_clear(t_stack *stack);
void	ft_delete(t_stack *stack);
void	ft_display(t_stack *stack);
void	ft_parsing(const char *str, t_stack *stack);
int		ft_atoi(const char *str);
void	ft_error(char *msg, int fd);

void	ft_swap(t_stack *stack);
t_node	*ft_pop(t_stack *stack);
void	ft_push(t_stack *stack_a, t_stack *stack_b);

#endif