/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 22:38:30 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/03 12:30:09 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./common_ps_def.h"
# include "../libft/libft.h"

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

/* push_swap.c */
void	ps_swap(t_ps *ps, int type);
void	ps_push(t_ps *a, t_ps *b, int type);
void	ps_rotate(t_ps *ps, int type);
void	ps_reverse_rotate(t_ps *ps, int type);

/* push_swap_utils.c */
t_ps	*ps_create(void);
int		ps_add_data(t_ps *ps, int data);
t_node	*ps_get_node(t_ps *ps, int position);
t_node	*ps_pop_top(t_ps *ps);
t_node	*ps_pop_bottom(t_ps *ps);

/* ps_utils.c */
int		ps_atoi(const char *str);
void	ps_free(char **str);
void	ps_error(int fd);
void	ps_parsing(const char *str, t_ps *a);
void	ps_display(int type);

/* ps_arr.c */
int		*ps_arr(t_ps *ps);
int		*ps_add_arr(t_ps *ps, int len);
int		ps_sorting_arr(int *arr, int len);

/* ps_sorting.c */
void	ps_init_sort(t_ps *a, t_ps *b, int *sorted);
void	ps_sort2(t_ps *a);
void	ps_sort3(t_ps *a);
void	ps_sorting(t_ps *a, t_ps *b, int *sotred);

#endif