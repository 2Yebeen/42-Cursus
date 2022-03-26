/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:29:54 by yeblee            #+#    #+#             */
/*   Updated: 2022/03/26 15:47:52 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	find;
	unsigned char	*new_s;

	if (!s)
		return (NULL);
	find = (unsigned char)c;
	new_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (new_s[i] == find)
			return ((new_s + i));
		i++;
	}
	return (0);
}
