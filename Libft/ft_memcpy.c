/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:23:11 by yeblee            #+#    #+#             */
/*   Updated: 2022/03/22 16:45:06 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dst_temp;
	const unsigned char	*src_temp;

    if (!dst && !src)
		return (NULL);
	dst_temp = (unsigned char *)dst;
	src_temp = (const unsigned char *)src;
	idx = 0;
	while (i++ < n)
		dst_temp[i] = src_temp[i];
	return (dst);
}