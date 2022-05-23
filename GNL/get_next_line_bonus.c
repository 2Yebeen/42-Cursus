/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:08:56 by yeblee            #+#    #+#             */
/*   Updated: 2022/05/23 17:10:32 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*gnl_get_line(char const *contents)
{
	size_t	len;
	char	*line;

	if (!contents)
		return (NULL);
	if (gnl_strchr(contents, '\n'))
		len = gnl_strchr(contents, '\n') - contents + 1;
	else
		len = gnl_strchr(contents, '\0') - contents;
	line = malloc(len + 1);
	if (line == NULL)
		return (NULL);
	gnl_strlcpy(line, contents, len + 1);
	return (line);
}

char	*gnl_set_remains(char *contents, size_t offset)
{
	char	*ret;

	ret = malloc(gnl_strlen(contents + offset) + 1);
	if (ret == NULL)
		return (NULL);
	gnl_strlcpy(ret, contents + offset, gnl_strlen(contents + offset) + 1);
	free(contents);
	contents = NULL;
	return (ret);
}

char	*gnl_read_file(char *contents, int fd)
{
	ssize_t	len;
	char	*buff;
	char	*temp;
	char	*ret;

	buff = malloc(BUFFER_SIZE + 1);
	if (buff == NULL)
		return (NULL);
	ret = contents;
	while (ret == NULL || !gnl_strchr(ret, '\n'))
	{
		len = read(fd, buff, BUFFER_SIZE);
		if (len <= 0)
			break ;
		buff[len] = '\0';
		temp = ret;
		ret = gnl_append_buff(ret, buff);
		free(temp);
	}
	free(buff);
	if (len < 0 || ret == NULL || *ret == '\0')
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

t_list	*gnl_get_node(t_list *head, int fd)
{
	t_list	*node;

	node = head->next;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		else
			node = node->next;
	}
	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->fd = fd;
	node->contents = NULL;
	node->prev = head;
	node->next = head->next;
	if (head->next)
		head->next->prev = node;
	head->next = node;
	return (node);
}

char	*get_next_line(int fd)
{
	static t_list	head;
	t_list			*node;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = gnl_get_node(&head, fd);
	if (!node)
		return (gnl_clear_node(node));
	node->contents = gnl_read_file(node->contents, fd);
	if (!node->contents)
		return (gnl_clear_node(node));
	line = gnl_get_line(node->contents);
	if (!line)
		return (NULL);
	node->contents = gnl_set_remains(node->contents, gnl_strlen(line));
	if (!node->contents)
		return (gnl_clear_node(node));
	return (line);
}

// #include <fcntl.h>
// int main(void)
// {
// 	int		fd;
// 	char	*prt;
// 	// fd = open("text.txt", O_RDONLY);
// 	fd = open("test2.txt", O_RDONLY);
// 	prt = get_next_line(fd);
// 	printf("%s\n",prt);
// 	prt = get_next_line(fd);
// 	printf("%s\n",prt);
// 	prt = get_next_line(fd);
// 	printf("%s\n",prt);
// 	system("leaks a.out");
// 	return (0);
// }