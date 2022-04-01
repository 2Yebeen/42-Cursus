/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 01:49:11 by yeblee            #+#    #+#             */
/*   Updated: 2022/03/26 16:12:25 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_des;
	size_t	len_src;

	len_des = ft_strlen(dest);
	len_src = ft_strlen(src);
	i = 0;
	if (len_des > dstsize)
		return (dstsize + len_src);
	while (src[i] && len_des + i + 1 < dstsize)
	{
		dest[len_des + i] = src[i];
		i++;
	}
	dest[len_des + i] = 0;
	return (len_des + len_src);
}
