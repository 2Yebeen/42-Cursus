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
	// exit(EXIT_FAILURE);
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
		exit_trap("excute error\n", 127);
}
