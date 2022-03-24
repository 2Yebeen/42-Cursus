/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:56:20 by marvin            #+#    #+#             */
/*   Updated: 2022/03/23 23:56:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	        i;
	char			*str;

	if (!s)
		return (0);
    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return (0);
	i = ft_strlen(s);
	if (i <= start)
    {
        str[0] = 0;
        return (str);
    }
    ft_strlcpy(str, s + start, len + 1)
    return (str);
}