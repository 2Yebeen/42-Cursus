/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:51:42 by yeblee            #+#    #+#             */
/*   Updated: 2022/04/14 18:00:19 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

/*ft_formats.c*/
int		ft_formats(va_list args, const char format);

/*ft_printbase.c*/
int		ft_printbase(va_list ap, const char format);
char	*base_type(const char type);

/*ft_printf.c*/
int		ft_printf(const char *str, ...);

/*ft_printnbr.c*/
size_t	ft_numlen(unsigned int num, int base);
char	*ft_pitoa(unsigned long long n, char *base);
char	*ft_uitoa(unsigned int n, char *base);
char	*ft_itoa(int n, char *base);

/*ft_printstr.c*/
int		ft_printchar(int chr);
int		ft_printstr(char *str);
int		ft_strlen(char *str);

#endif