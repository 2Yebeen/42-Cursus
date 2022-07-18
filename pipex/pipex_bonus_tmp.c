/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:54:00 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/18 13:48:57 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	create_pipe(char *argv, char *envp[])
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
		else
			close(fd[WRITE_END]);
		find_path(argv, envp);
	}
	else
	{
		close(fd[WRITE_END]);
		if (dup2(fd[READ_END], STDIN_FILENO) == -1)
			exit_msg("duplicate error\n", 1);
		else
			close(fd[READ_END]);
		waitpid(pid, NULL, WNOHANG);
	}
}

void	here_doc(char *limiter)
{
	pid_t	pid;
	int		fd[2];
	char	*line;

	if (pipe(fd) == -1)
		exit_msg("pipe error\n", 1);
	pid = fork();
	if (pid == -1)
		exit_msg("fork error\n", 1);
	if (pid == 0)
	{
		close(fd[READ_END]);
		while (get_next_line(&line))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			write(fd[WRITE_END], line, ft_strlen(line));
		}
	}
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

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			i = 3;
			outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND | O_CLOEXEC, 0777);
			if (outfile == -1)
				exit_msg("file error\n", 1);
			here_doc(argv[2]);
		}
		else
		{
			i = 2;
			outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC, 0777);
			if (outfile == -1)
				exit_msg("file error\n", 1);
			infile = open(argv[1], O_RDONLY | O_CLOEXEC, 0777);
			if (infile == -1)
				exit_msg("file error\n", 1);
			if (dup2(infile, STDIN_FILENO) == -1)
				exit_msg("duplicate error\n", 1);
			else
				close(infile);
		}
		while (i < argc - 2)
			create_pipe(argv[i++], envp);
		find_path(argv[argc - 2], envp);
	}
	exit_msg("arguments error\n", 1);
}
