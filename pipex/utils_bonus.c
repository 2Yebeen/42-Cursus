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
#include <limits.h>

void	arg_error(int bonus)
{
	ft_putstr_fd("\033[31mError: Argumentos invalidos\n\e[0m", 2);
	if (bonus)
	{
		ft_putstr_fd(
			"Pruebe: ./pipex archivo1 cmd1 cmd2... cmdn archivo2\n", 1);
		ft_putstr_fd(
			"O: ./pipex here_doc LIMITADOR cmd1 cmd2 archivo\n", 1);
	}
	else
	{
		ft_putstr_fd("Pruebe: ./pipex archivo1 cmd1 cmd2 archivo2\n", 1);
	}	
	exit(EXIT_SUCCESS);
}

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
int	open_file(char *argv, int i)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND | O_CLOEXEC, 0777);
	else if (i == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC, 0777);
	else if (i == 2)
		file = open(argv, O_RDONLY | O_CLOEXEC, 0777);
	if (file == -1)
		error();
	return (file);
}