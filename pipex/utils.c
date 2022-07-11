/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:53:51 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/11 11:58:06 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_trap(char *str, int sig)
{
	write(2, str, ft_strlen(str));
	exit(sig);
}

char	*set_up_path(char *cmd, char *envp[])
{
	int		i;
	char	**paths;
	char	*part_path;

	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		part_path = ft_strjoin(part_path, cmd);
		if (!access(part_path, F_OK))
			return (part_path);
		free(part_path);
		i++;
	}
	free(paths);
	return (NULL);
}

void	find_path(char *argv, char *envp[])
{
	char	*path;
	char	**cmd;

	cmd = ft_split(argv, ' ');
	if (!access(cmd[0], F_OK))
	{
		if (execve(cmd[0], cmd, envp) == -1)
			exit_trap("excute error\n", 127);
	}
	path = set_up_path(cmd[0], envp);
	if (!path)
	{
		free(cmd);
		exit_trap("command not found\n", 127);
	}
	if (execve(path, cmd, envp) == -1)
		exit_trap("excute error\n", 127);
}
