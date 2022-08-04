/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 23:07:19 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/04 16:43:37 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ps_error(int fd)
{
	if (fd)
		ft_putstr_fd("Error\n", fd);
	exit(1);
}

void	ps_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

int	ps_atoi(const char *str)
{
	size_t	i;
	long	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		if ((num > 2147483647 && sign == 1) || (num > 2147483648 && sign == -1))
			ps_error(2);
		i++;
	}
	if (str[i])
		ps_error(2);
	return (num * sign);
}

void	ps_parsing(const char *str, t_ps *a)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = ft_split(str, ' ');
	if (!tmp[i])
		ps_error(2);
	while (tmp[i])
	{
		if (!ps_push_bottom(a, ps_atoi(tmp[i])))
			ps_error(2);
		i++;
	}
	ps_free(tmp);
}

void	ps_display(int type)
{
	char	*str;

	str = NULL;
	if (type == NONE)
		return ;
	if (type == SA || type == SB || type == SS)
		str = ft_strjoin(str, "s");
	else if (type == PA || type == PB)
		str = ft_strjoin(str, "p");
	else if (type == RA || type == RB || type == RR)
		str = ft_strjoin(str, "r");
	else if (type == RRA || type == RRB || type == RRR)
		str = ft_strjoin(str, "rr");
	if (type == SA || type == PA || type == RA || type == RRA)
		str = ft_strjoin(str, "a");
	else if (type == SB || type == PB || type == RB || type == RRB)
		str = ft_strjoin(str, "b");
	else if (type == RR || type == RRR)
		str = ft_strjoin(str, "r");
	str = ft_strjoin(str, "\n");
	ft_putstr_fd(str, 1);
}
