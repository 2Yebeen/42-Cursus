/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:18:06 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/30 10:47:09 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>

char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	ft_putstr_fd(char *s, int fd);
void	*ft_memset(void *ptr, int value, size_t len);
char	*base_type(const char type);
int	    ft_checkbase(va_list ap, const char format);
int     ft_parsing(va_list args, const char format);
int     ft_formats(va_list ap, const char *format);
void	ft_printbase(unsigned long long num, const char *base);
int	    ft_printi(int n, const char *base);
int	    ft_printu(unsigned int n, const char *base);
int 	ft_printp(unsigned long long n, const char *base);
int 	ft_printf(const char *format, ...);
int	    ft_printchar(int chr);
int 	ft_printstr(char *str);

#endif
