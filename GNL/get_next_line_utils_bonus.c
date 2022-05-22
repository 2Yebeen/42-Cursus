/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:09:13 by yeblee            #+#    #+#             */
/*   Updated: 2022/05/19 12:09:15 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    *ft_calloc(size_t count, size_t size)
{
        void    *ptr;
        size_t  len;

        len = count * size;
        if (count > 0 && size > 0 && size != (len / count))
                return (0);
        ptr = malloc(len);
        if (!ptr)
                return (0);
        ft_memset(ptr, 0, len);
        return (ptr);
}

