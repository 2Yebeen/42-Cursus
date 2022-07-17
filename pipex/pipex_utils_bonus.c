/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:53:36 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/15 16:50:18 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex_bonus.h"
#include <stdio.h>

int	get_next_line(char **line)
{
	char	*buffer;
	int		readed;
	int		i;
	char	c;

	i = 0;
	readed = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	readed = read(0, &c, 1);
	while (readed && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		readed = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (readed);
}

void	exit_msg(char *str, int sig)
{
	char *ret;

	ret = ft_strjoin("Error : ", str);
	write(2, ret, ft_strlen(ret));
	exit(sig);

}

char	*set_path(char *cmd, char *envp[])
{
	int		i;
	char	*path;
	char	**paths;

	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], cmd);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

void	find_path(char *argv, char *envp[])
{
	char	*cmd;
	char	*path;
	char	**tmp;

	tmp = ft_split(argv, ' ');
	cmd = ft_strjoin("/", tmp[0]);
	path = set_path(cmd, envp);
	free(cmd);
	if (execve(path, tmp, envp) == -1)
		exit_msg("command not found\n", 127);
}