/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:58:17 by yeblee            #+#    #+#             */
/*   Updated: 2022/03/23 19:58:35 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *n)
{
	t_list	*temp;

	if (!lst || !n)
		return ;
	temp = *lst;
	if (!temp)
	{
		ft_lstadd_front(lst, n);
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = n;
	return ;
}
