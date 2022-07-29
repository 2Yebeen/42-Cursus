/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:56:26 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/29 15:06:36 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# define LONG_MAX 	9223372036854775807

typedef struct s_node
{
	int				data;
	struct s_node	*pLLink;
	struct s_node	*pRLink;
}			t_node;

typedef struct s_stack
{
	int		count;	
	t_node	header;
}	t_stack;


int	ft_atoi(const char *str, int *err);

#endif