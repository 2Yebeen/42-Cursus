/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:18:49 by yeblee            #+#    #+#             */
/*   Updated: 2022/03/24 14:11:57 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ischar(char c, char s)
{
	if (c == s)
		return (1);
	return (0);
}

static char	**ft_malloc_error(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	arr = NULL;
	return (NULL);
}

static size_t	ft_countchar(char const *s, char c)
{
	unsigned int	cnt;
	char			*temp;

	temp = (char *)s;
	if (!s[0])
		return (0);
	cnt = 0;
	while (*temp)
	{
		while (*temp && ft_ischar(c, *temp))
			temp++;
		if (*temp && !ft_ischar(c, *temp))
			cnt++;
		while (*temp && !ft_ischar(c, *temp))
			temp++;
	}
	return (cnt);
}

static void	ft_get_next_str(char **next_str, size_t *len, char c)
{
	size_t	i;

	*next_str += *len;
	*len = 0;
	i = 0;
	while (**next_str && ft_ischar(**next_str, c))
		(*next_str)++;
	while ((*next_str)[i])
	{
		if (ft_ischar((*next_str)[i], c))
			return ;
		(*len)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	char	*temp;
	size_t	len;
	size_t	next_len;
	size_t	idx;

	if (!s)
		return (NULL);
	len = ft_countchar(s, c);
	arr = (char **)malloc(sizeof(char *) * (len + 1));
	if (!arr)
		return (NULL);
	temp = (char *)s;
	next_len = 0;
	idx = 0;
	while (idx < len)
	{
		ft_get_next_str(&temp, &next_len, c);
		arr[idx] = (char *)malloc(sizeof(char) * (next_len + 1));
		if (!(arr[idx]))
			return (ft_malloc_error(arr));
		ft_strlcpy(arr[idx++], temp, next_len + 1);
	}
	arr[idx] = NULL;
	return (arr);
}
