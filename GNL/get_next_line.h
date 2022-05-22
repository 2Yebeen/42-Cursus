/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:08:49 by yeblee            #+#    #+#             */
/*   Updated: 2022/05/19 15:02:27 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_gnl_data
{
    char                *pContent;
    struct s_gnl_data   *pNext;
} t_gnl_data;

typedef struct  s_gnl_list
{
    struct s_gnl_data   *pHead;
    struct s_gnl_data   *pTail;
    
} t_gnl_list;

// char	*get_next_line(int fd);

// size_t	ft_strlen(const char *s);
// char	*ft_strdup(const char *str);
// char	*ft_strchr(const char *s, int c);
// char	*ft_strjoin(char const *s1, char const *s2);
// void    *ft_memset(void *ptr, int value, size_t len);

#endif
