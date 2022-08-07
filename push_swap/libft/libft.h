/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:35:27 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/07 22:34:23 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 10

typedef struct s_gnl_list
{
	int					fd;
	char				*contents;
	struct s_gnl_list	*prev;
	struct s_gnl_list	*next;
}	t_list;

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memset(void *ptr, int value, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dest, const char *src, size_t dstsize);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	gnl_strlen(char const *s);
char	*gnl_clear_node(t_list *node);
char	*gnl_strchr(char const *s, int c);
char	*gnl_append_buff(char const *save, char const *buf);
size_t	gnl_strlcpy(char *dst, char const *src, size_t dstsize);
char	*get_next_line(int fd);

#endif