/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 00:26:18 by marvin            #+#    #+#             */
/*   Updated: 2022/03/24 00:26:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *str;
    size_t  len_s1;
    size_t  len_s2;
    size_t  i;
    size_t  j;

    if (!s1 && !s2)
        return (0);
    len_s1 = ft_strlen(s1);
    len_s2 = ft_strlen(s2);
    str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
    if(!str)
        return (0);
    i = 0;
    j = 0;
    while (i++ < len_s1)
        str[i] = s1[i];
    while (j++ < len_s2)
        str[i + j] = s2[j];
    str[i + j] = 0;
    return (str);
}