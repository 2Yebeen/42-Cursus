/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:09:02 by yeblee            #+#    #+#             */
/*   Updated: 2022/05/26 11:54:34 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_gnl_list
{
	int					fd;
	char				*contents;
	struct s_gnl_list	*prev;
	struct s_gnl_list	*next;
}	t_list;

size_t	gnl_strlen(char const *s);
char	*gnl_strchr(char const *s, int c);
size_t	gnl_strlcpy(char *dst, char const *src, size_t dstsize);
char	*gnl_clear_node(t_list *node);
char	*gnl_append_buff(char const *save, char const *buf);
char	*get_next_line(int fd);

#endif