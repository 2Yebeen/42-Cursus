/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:53:36 by yeblee            #+#    #+#             */
/*   Updated: 2022/07/18 17:39:33 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "./libft/libft.h"

# define READ_END	0
# define WRITE_END	1

void	create_pipex(char *argv, char *envp[]);
void	line_write(int fd, char *limiter);
void	here_doc(char *limiter);
void	exit_msg(char *str, int sig);
char	*set_path(char *cmd, char *envp[]);
void	find_path(char *argv, char *envp[]);
int	    ft_openfile(char *argv, int type);

#endif