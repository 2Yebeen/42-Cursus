/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:51:42 by yeblee            #+#    #+#             */
/*   Updated: 2022/04/12 19:46:22 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_formats(va_list args, const char format);
int	ft_strlen(char *str);
int	ft_printchar(int chr);
int	ft_printstr(char *str);
int	ft_printbase(va_list args, const char format);
int	ft_putnbr(void n, int base);
int	ft_baselen(char *base);

#endif