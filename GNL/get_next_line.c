/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:08:39 by yeblee            #+#    #+#             */
/*   Updated: 2022/05/19 12:08:43 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	*get_clean(t_gnl_list *lst)
{
    t_gnl_list	*del;
	t_gnl_list	*tmp;

	if (!lst)
		return (NULL);
    del = lst;
	while (del)
	{
		tmp = del->pNext;
		free(del->pContent);
        del->pContent = NULL;
		free(del);
        del = NULL;
		del = tmp;
	}
    free(tmp);
    tmp = NULL;
    return (NULL);
}

char    *get_line(t_gnl_list *lst)
{
    t_gnl_list   *ret;

    ret = lst;
    while (ret->pNext)
        ret = ret->pNext;
    return (ret->pContent);
}

void    get_read_file(int fd, t_gnl_list *lst)
{\
    int     nr;
    char    *content;

    content = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    nr = 1;
    while (nr > 0)
    {
        nr = read(fd, content, BUFFER_SIZE);
        if (nr == -1)
        {
            get_clean(lst);
            break;
        }
        content[nr] = 0;
        lst->pContent = ft_strjoin(lst->pContent, content);
        if (ft_strchr(content, '\n'))
            break;
    }
    free(content);
}

char	*get_next_line(int fd)
{
    static t_gnl_list    *lst;
    char                 *ret;
    size_t               nr;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    lst = malloc(sizeof(t_gnl_list));
    lst->pContent = NULL;
    lst->pNext = NULL;
    get_read_file(fd, lst);
    ret = get_line(lst);
    return (ret);
}

#include <fcntl.h>

int main(void)
{
    int fd;
	char	*get;
    fd = open("text.txt", O_RDONLY);
    get = get_next_line(fd);
	printf("%s\n", get);

    get = get_next_line(fd);
	printf("%s\n", get);

    get = get_next_line(fd);
	printf("%s\n", get);

    system("leaks a.out");

    return 0;
}