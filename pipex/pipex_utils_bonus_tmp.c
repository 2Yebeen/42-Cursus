/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus_tmp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:53:36 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/18 14:05:00 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex_bonus.h"

void	exit_msg(char *str, int sig)
{
	char *ret;

	ret = ft_strjoin("Error : ", str);
	write(2, ret, ft_strlen(ret));
	exit(sig);

}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	if (*s && fd >= 0)
		write(fd, s, ft_strlen(s));
	write(1, "\n", 1);
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
		if (access(path, W_OK) == 0){
			ft_putstr_fd(path, 1);
			return (path);
		}
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
	ft_putstr_fd(path, 1);
	if (execve(path, tmp, envp) == -1)
		exit_msg("command not found\n", 127);
}