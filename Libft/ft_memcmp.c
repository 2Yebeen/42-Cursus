/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 02:08:29 by yeblee            #+#    #+#             */
/*   Updated: 2022/03/25 02:08:29 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_memcmp(const void *b1, const void *b2, size_t n)
{
    unsigned char *s1;
    unsigned char *s2;
    int            i;

    if ((b1 == 0 && b2 == 0) || n == 0)
        return (0);
    s1 = (unsigned char *)b1;
    s2 = (unsigned char *)b2;
    i = -1;
    while (++i < n)
        if (s1[i] != s2[i])
            break ;
    return (s1[i] - s2[i]);
}
