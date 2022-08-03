/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 23:07:19 by yeblee            #+#    #+#             */
/*   Updated: 2022/08/03 00:29:02 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    ps_error(int fd)
{
    if (fd)
        ft_pusstr_fd("Error\n", fd);
    exit(1);
}

void    ps_free(char **str)
{
    int i;

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

int ps_atoi(const char *str)
{
    size_t  i;
    long    num;
    int     sign;

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
        if ((num > INTMAX && sign == 1) || (num > INTMAX+1 && sign == -1))
            ps_error(2);
        i++;
    }
    if (str[i])
        ps_error(2);    
    return (num * sign);
}

void    ps_parsing(const char *str, t_ps *a)
{
    int     i;
    char    **tmp;

    i = 0;
    tmp = ft_split(str, ' ');
    if (!tmp[i])
        ps_error(2);
    while (tmp[i])
    {
        if (!ps_add_data(a, ps_atoi(tmp[i])))
            ps_error(2);
        i++;
    }
    ps_free(tmp);
}

void    ps_display(type)
{
    char    *str;
        
    if (type == SA)
        str = "sa\n";
    else if (type == SB)
        str = "sb\n";
    else if (type == SS)
        str = "ss\n";
    else if (type == PA)
        str = "pa\n";
    else if (type == PB)
        str = "pb\n";
    else if (type == RA)
        str = "ra\n";
    else if (type == RB)
        str = "rb\n";
    else if (type == RR)
        str = "rr\n";
    else if (type == RRA)
        str = "rra\n";
    else if (type == RRB)
        str = "rrb\n";
    else if (type == RRR)
        str = "rrr\n";
    ft_putstr_fd(str, 1);
}
