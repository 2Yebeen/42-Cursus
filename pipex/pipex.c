/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:54:00 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/18 10:44:20 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char *argv[], char *envp[], int *fd)
{
	int	infile;

	infile = open(argv[1], O_RDONLY | O_CLOEXEC, 0777);
	if (infile == -1)
		exit_msg("file error\n", 1);
	else
	{
		if (dup2(fd[WRITE_END], STDOUT_FILENO) == -1)
			exit_msg("duplicate error\n", 1);
		else 
			close(fd[WRITE_END]);
		if (dup2(infile, STDIN_FILENO) == -1)
			exit_msg("duplicate error\n", 1);
		else
			close(fd[READ_END]);
		close(infile);
		find_path(argv[2], envp);
	}
}

void	parent_process(char *argv[], char *envp[], int *fd)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC, 0777);
	if (outfile == -1)
		exit_msg("file error\n", 1);
	else
	{
		if (dup2(fd[READ_END], STDIN_FILENO) == -1)
			exit_msg("duplicate error\n", 1);
		else
			close(fd[READ_END]);
		if (dup2(outfile, STDOUT_FILENO) == -1)
			exit_msg("duplicate error\n", 1);
		else
			close(fd[WRITE_END]);
		close(outfile);
		find_path(argv[3], envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			exit_msg("pipe error\n", 1);
		pid = fork();
		if (pid == -1)
			exit_msg("fork error\n", 1);
		if (pid == 0)
			child_process(argv, envp, fd);
		waitpid(pid, NULL, WNOHANG);
		parent_process(argv, envp, fd);
	}
	else
		exit_msg("arguments error\n", 1);
	return (0);
}
