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
    t_gnl_data	*del;
	t_gnl_data	*tmp;

	if (!lst)
		return (NULL);
    del = lst->pHead;
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

void    get_line(t_gnl_list *lst)
{
}
t_gnl_data *get_buff(char *content)
{
    t_gnl_data *ret;

    ret = malloc(sizeof(t_gnl_data));
    ret->pContent = content;
    ret->pNext = NULL;

    return (ret);
}
void    get_read_file(int fd, t_gnl_list *lst)
{
    t_gnl_data  *buff;
    t_gnl_data  *last;
    int         nr;
    char        *content;

    last = lst->pHead;
    content = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    nr = 1;
    while (nr > 0)
    {
        nr = read(fd, content, BUFFER_SIZE);
        if (nr == -1)
            get_clean(lst);
        buff = get_buff(content);
        printf("%s\n", buff->pContent);
        buff->pContent[nr] = 0;
        buff->pNext = NULL;
        last->pNext = buff;
        lst->pTail->pNext = last->pNext;

    }
}

char	*get_next_line(int fd)
{
    static t_gnl_list    *lst;
    // char                 *ret;
    size_t               nr;

    t_gnl_data          *tester;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    lst = malloc(sizeof(t_gnl_list));
    lst->pHead = malloc(sizeof(t_gnl_data));
    lst->pTail = malloc(sizeof(t_gnl_data));
    lst->pHead->pContent = NULL;
    lst->pHead->pNext = NULL;
    lst->pTail->pContent = NULL;
    lst->pTail->pNext = NULL;
    get_read_file(fd, lst);
    tester = lst->pHead;
    printf("^^%s\n", tester->pNext->pContent);
    // get_line(lst); 
    get_clean(lst);
    return (NULL);
}

#include <fcntl.h>

int main(void)
{
    int fd;

    fd = open("text.txt", O_RDONLY);
    get_next_line(fd);
    // system("leaks a.out");

    return 0;
}