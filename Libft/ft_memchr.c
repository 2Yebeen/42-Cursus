/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:29:54 by yeblee            #+#    #+#             */
/*   Updated: 2022/03/22 17:43:13 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*new_s;
	unsigned char	find;

	if (!s)
		return (NULL);
	new_s = (unsigned char *)s;
	find = (unsigned char)c;
	i = 0;
	while (i++ < n)
	{
		if (new_s[i] == find)
			return((new_s + i));
	}
	return (0);
}
