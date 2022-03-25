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
	int				i;
	unsigned char	find;
	unsigned char	*new_s;

	if (!s)
		return (NULL);
	find = (unsigned char)c;
	new_s = (unsigned char *)s;
	i = -1;
	while (++i < n)
		if (new_s[i] == find)
			return((new_s + i));
	return (0);
}
