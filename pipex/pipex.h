/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:53:36 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/12 13:00:38 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../Libft/libft.h" 

void	child_process(char *argv[], char *envp[], int *fd);
void	parent_process(char *argv[], char *envp[], int *fd);
void	find_path(char *argv, char *envp[]);
char	*set_up_path(char *cmd, char *envp[]);
void	exit_msg(char *str, int sig);

# define READ_END	0
# define WRITE_END	1

#endif