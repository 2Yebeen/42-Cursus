/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:56:59 by yeblee            #+#    #+#             */
/*   Updated: 2022/04/09 15:54:19 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t len)
{
	size_t			i;
	unsigned char	v;
	unsigned char	*p;

	i = 0;
	v = (unsigned char)value;
	p = (unsigned char *)ptr;
	while (i++ < len)
		*p++ = v;
	return (ptr);
}
