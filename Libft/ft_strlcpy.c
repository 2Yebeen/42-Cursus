/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <yeblee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 01:35:25 by marvin            #+#    #+#             */
/*   Updated: 2022/03/26 01:35:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_src;
    
	len_src = ft_strlen(src);
    if (!dstsize)
    	return (len_src);
    i = 0;
    while (i + 1 < dstsize && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (len_src);
}
