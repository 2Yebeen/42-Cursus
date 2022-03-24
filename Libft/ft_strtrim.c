/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 00:49:40 by marvin            #+#    #+#             */
/*   Updated: 2022/03/24 00:49:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strtrim(char const *s1, char const *set)
{
    char    *str;
    size_t  start;
    size_t  end;

    if (!s1)
        return (0);
    if (!set)
        return (ft_strdup(s1));
    start = 0;
    end = ft_strlen(s1) - 1;
    while (s1[start] && ft_strchr(set, s1[start]))
        start++;
    while ((end > 0) && s1[end] && ft_strchr(set, s1[end]))
        end--;
    if (start > end)
        return (ft_strdup(""));
    str = (char *)malloc(sizeof(char) * (end - start + 1));
    if (!str)
        return (0);
    ft_strlcpy(str, s1 + start, end - start + 1);
    return (str);
}