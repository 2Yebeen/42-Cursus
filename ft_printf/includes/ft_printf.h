/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:51:42 by yeblee            #+#    #+#             */
/*   Updated: 2022/04/15 20:08:52 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

/*ft_formats.c*/
int		ft_formats(va_list args, const char format);

/*ft_checkbase.c*/
int		ft_checkbase(va_list ap, const char format);
char	*base_type(const char type);

/*ft_printf.c*/
int		ft_printf(const char *str, ...);

/*ft_printbase.c*/
int		ft_printi(int n, const char *base);
int		ft_printu(unsigned int n, const char *base);
int		ft_printp(unsigned long long n, const char *base);
void	ft_printbase(unsigned long long num, const char *base);

/*ft_printstr.c*/
int		ft_printchar(int chr);
int		ft_printstr(char *str);
#endif