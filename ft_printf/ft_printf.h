/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:51:42 by yeblee            #+#    #+#             */
/*   Updated: 2022/04/13 12:05:14 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>

/*ft_printf.c*/
int		ft_printf(const char *str, ...);

/*ft_formats.c*/
int		ft_formats(va_list args, const char format);

/*ft_printstr.c*/
int		ft_strlen(char *str);
int		ft_printchar(int chr);
int		ft_printstr(char *str);

#endif