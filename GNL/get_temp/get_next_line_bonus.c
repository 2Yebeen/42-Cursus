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

char	*gnl_get_line(char const *contents)
{
	size_t	len;
	char	*line;

	if (gnl_strchr(contents, '\n'))
	{
		len = gnl_strchr(contents, '\n') - contents + 1;
	}
	else
	{
		len = gnl_strchr(contents, '\0') - contents;
	}
	line = malloc(len + 1);
	if (line == NULL)
		return (NULL);
	gnl_strlcpy(line, contents, len + 1);
	return (line);
}

char	*gnl_set_remains(char **contents, size_t offset)
{
	char	*new;

	new = malloc(gnl_strlen(*contents + offset) + 1);
	if (new == NULL)
		return (NULL);
	gnl_strlcpy(new, *contents + offset, gnl_strlen(*contents + offset) + 1);
	free(*contents);
	*contents = NULL;
	return (new);
}
char	*gnl_read_file(char **contents, int fd)
{
	char	*buf;
	ssize_t	nread;
	char	*temp;
	char	*new;

	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
	{
		free(*contents);
		*contents = NULL;
		return (NULL);
	}
	nread = 0;
	new = *contents;
	while (new == NULL || !gnl_strchr(new, '\n'))
	{
		nread = read(fd, buf, BUFFER_SIZE);
		if (nread <= 0)
			break ;
		buf[nread] = '\0';
		temp = new;
		new = gnl_append_buf(new, buf);
		free(temp);
	}
	free(buf);
	buf = NULL;
	if (nread < 0 || new == NULL || *new == '\0')
	{
		free(new);
		new = NULL;
		return (NULL);
	}
	return (new);
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

char	*get_next_line_bonus(int fd)
{
	static t_list	head;
	t_list			*node;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = gnl_get_node(&head, fd);
	if (node == NULL)
		return (NULL);
	node->contents = gnl_read_file(&(node->contents), fd);
	if (node->contents == NULL)
	{
		gnl_clear_node(&node);
		return (NULL);
	}
	line = gnl_get_line(node->contents);
	if (line == NULL)
	{
		gnl_clear_node(&node);
		return (NULL);
	}
	node->contents = gnl_set_remains(&(node->contents), gnl_strlen(line));
	if (node->contents == NULL)
	{
		gnl_clear_node(&node);
		return (NULL);
	}
	return (line);
}