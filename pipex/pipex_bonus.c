/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:54:00 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/15 16:53:10 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child_process(char *argv, char **envp)
{
	pid_t	pid;
	int		p[2];

	if (pipe(p) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
	{
		close(p[READ_END]);
		dup2(p[1], STDOUT_FILENO);
		execute(argv, envp);
	}
	else
	{
		close(p[WRITE_END]);
		dup2(p[READ_END], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	here_doc(char *limiter, int argc)
{
	pid_t	reader;
	int		p[2];
	char	*line;

	if (argc < 6)
		arg_error(1);
	if (pipe(p) == -1)
		error();
	reader = fork();
	if (reader == 0)
	{
		close(p[READ_END]);
		while (get_next_line(&line))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			write(p[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(p[WRITE_END]);
		dup2(p[READ_END], STDIN_FILENO);
		wait(NULL);
	}
}

// void	dup_close(src, dst)
// {
// 	dup2(src, dst);
// 	close(src);
// }

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	filein;
	int	fileout;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			i = 3;
			fileout = open_file(argv[argc - 1], 0);
			here_doc(argv[2], argc);
		}
		else
		{
			i = 2;
			fileout = open_file(argv[argc - 1], 1);
			filein = open_file(argv[1], 2);
			dup2(filein, STDIN_FILENO);
			close(filein);
		}
		while (i < argc - 2)
			child_process(argv[i++], envp);
		execute(argv[argc - 2], envp);
	}
	arg_error(1);
}
