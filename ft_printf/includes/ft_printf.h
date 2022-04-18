/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:47:53 by yeblee            #+#    #+#             */
/*   Updated: 2022/04/18 19:47:56 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

int		ft_printf(const char *str, ...);

int		ft_parsing(va_list args, const char format);
int		ft_formats(va_list ap, const char *format);

char	*base_type(const char type);
int		ft_checkbase(va_list ap, const char format);

int		ft_printi(int n, const char *base);
int		ft_printu(unsigned int n, const char *base);
int		ft_printp(unsigned long long n, const char *base);
void	ft_printbase(unsigned long long num, const char *base);

int		ft_printchar(int chr);
int		ft_printstr(char *str);

#endif