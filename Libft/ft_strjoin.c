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
    size_t  len;
    size_t  i;
    size_t  j;

    if (!s1 && !s2)
        return (0);
    len = ft_strlen(s1) + ft_strlen(s2);
    str = (char *)malloc(sizeof(char) * (len + 1));
    if(!str)
        return (0);
    i = 0;
    j = 0;
    while (i < ft_strlen(s1))
    {
        str[i] = s1[i];
        i++;
    }
    while (j < ft_strlen(s2))
    {
        str[i + j] = s2[j];
        j++;
    }
    str[i + j] = 0;
    return (str);
}
