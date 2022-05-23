/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:09:02 by yeblee            #+#    #+#             */
/*   Updated: 2022/05/23 17:06:42 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

typedef struct s_gnl_list
{
	int				   fd;
	char			    *contents;
	struct s_gnl_list	*prev;
	struct s_gnl_list	*next;
}	t_list;

size_t	gnl_strlen(char const *s);
void	gnl_clear_node(t_list **node);
char	*gnl_strchr(char const *s, int c);
char	*gnl_append_buff(char const *save, char const *buf);
size_t	gnl_strlcpy(char *dst, char const *src, size_t dstsize);

#endif