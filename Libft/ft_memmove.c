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
	unsigned char			*new_dest;
	const unsigned char		*new_src;

	if (dest == src || n == 0)
		return (dest);
	new_dest = (unsigned char *)dest;
	new_src = (const unsigned char *)src;
	if (dest < src)
	{
		while (n--)
			*new_dest++ = *new_src++;
	}
	else
	{
		new_dest += (n - 1);
		new_src += (n - 1);
		while (n--)
			*new_dest-- = *new_src--;
	}
	return (dest);
}
