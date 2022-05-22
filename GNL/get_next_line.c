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

void	free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

char *get_next_line(int fd)
{
    static char *backup;
    char        *buf;
    char        *ret;

    if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
        return (NULL);
    buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buf)
        return (NULL);
    ret = read_line(fd, buf, backup);
    if (!ret)
        return (NULL);
    free_ptr(&buf);
    backup = extract(ret);
    return (ret);
}

#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>

int mian(void) {
    int fd;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1) return (1);
    printf("fd : %d\n", fd);
    close(fd);
    return (0);
}