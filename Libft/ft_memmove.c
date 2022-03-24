/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:19:06 by yeblee            #+#    #+#             */
/*   Updated: 2022/03/22 19:18:29 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*new_dest;
	unsigned char		*new_src;

	if (dest == src || n == 0)
		return (dest);
	
	if (dest < src)
		memcpy(dest, src, n);
	else
	{
		i = -1;
		new_dest = (unsigned char *)dest + (n - 1);
		new_src = (unsigned char *)src + (n - 1);
		while (++i < n)
			new_dest[i] = new_src[i];
	}
	return (dest);
}
