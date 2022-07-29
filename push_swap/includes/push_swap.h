/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:56:26 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/29 00:41:35 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int             data;
	struct s_node	*pLLink;
	struct s_node	*pRLink;
} t_node;

typedef struct s_stack
{
	int     currentElementCount;	
	t_node  headerNode;
}	t_stack;


#endif