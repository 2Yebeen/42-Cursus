/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:54:00 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/20 10:42:50 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	create_pipex(char *argv, char *envp[])
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		exit_msg("pipe error\n", 1);
	pid = fork();
	if (pid == -1)
		exit_msg("fork error\n", 1);
	if (pid == 0)
	{
		close(fd[READ_END]);
		if (dup2(fd[WRITE_END], STDOUT_FILENO) == -1)
			exit_msg("duplicate error\n", 1);
		find_path(argv, envp);
	}
	else
	{
		close(fd[WRITE_END]);
		if (dup2(fd[READ_END], STDIN_FILENO) == -1)
			exit_msg("duplicate error\n", 1);
		waitpid(pid, NULL, WNOHANG);
	}
}

void	line_write(int fd, char *limiter)
{
	char	*line;

	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
			exit(EXIT_SUCCESS);
		write(fd, line, ft_strlen(line));
		free(line);
	}
}

void	here_doc(char *limiter)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		exit_msg("pipe error\n", 1);
	pid = fork();
	if (pid == -1)
		exit_msg("fork error\n", 1);
	if (pid == 0)
		line_write(fd[WRITE_END], limiter);
	else
	{
		close(fd[WRITE_END]);
		dup2(fd[READ_END], STDIN_FILENO);
		waitpid(pid, NULL, WNOHANG);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	int	i;
	int	infile;
	int	outfile;

	i = 2;
	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			i = 3;
			outfile = ft_openfile(argv[argc - 1], 0);
			here_doc(argv[2]);
		}
		else
		{
			outfile = ft_openfile(argv[argc - 1], 1);
			infile = ft_openfile(argv[1], 2);
			dup2(infile, STDIN_FILENO);
			close(infile);
		}
		dup2(outfile, STDOUT_FILENO);
		while (i < argc - 2)
			create_pipex(argv[i++], envp);
		find_path(argv[argc - 2], envp);
	}
}
