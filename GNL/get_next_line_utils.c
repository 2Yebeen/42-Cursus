/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:09:08 by yeblee            #+#    #+#             */
/*   Updated: 2022/05/19 15:55:17 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(char const *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

char	*gnl_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
	if (!c)
		return ((char *)s + i);
	return (0);
}

char	*gnl_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*str;

	len = gnl_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1 && s2)
		return (gnl_strdup(s2));
	else if (s1 && !s2)
		return (gnl_strdup(s1));
	s = (char *)malloc(sizeof(char) * ((gnl_strlen(s1) + gnl_strlen(s2)) + 1));
	if (!s)
		return (NULL);
	i = -1;
	while (s1[++i])
		s[i] = s1[i];
	j = -1;
	while (s2[++j])
		s[i + j] = s2[j];
	s[i + j] = '\0';
	return (s);
}

void	*gnl_calloc(size_t elementCount, size_t elementSize)
{
	size_t	i;
	char	*ret;

	ret = malloc(elementSize * elementCount);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < elementSize * elementCount)
	{
		ret[i] = '\0';
		i++;
	}
	return (ret);
}
