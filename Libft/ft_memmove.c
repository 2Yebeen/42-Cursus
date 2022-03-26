/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:19:06 by yeblee            #+#    #+#             */
/*   Updated: 2022/03/26 17:56:00 by yeblee           ###   ########.fr       */
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
	i = 0;
	new_dest = (unsigned char *)dest;
	new_src = (unsigned char *)src;
	if (dest < src)
	{
		while (i < n)
		{
			new_dest[i] = new_src[i];
			i++;
		}
	}
	else
		while (++i <= n)
			new_dest[n - i] = new_src[n - i];
	return (dest);
}
