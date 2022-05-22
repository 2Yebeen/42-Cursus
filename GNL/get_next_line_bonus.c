/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeblee <yeblee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:08:56 by yeblee            #+#    #+#             */
/*   Updated: 2022/05/19 12:08:58 by yeblee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// void	*get_clean(t_gnl_list *lst)
// {
//     t_gnl_data	*del;
// 	t_gnl_data	*tmp;

// 	if (!lst)
// 		return (NULL);
//     del = lst->pHead;
// 	while (del)
// 	{
// 		tmp = del->pNext;
// 		free(del->pContent);
//         del->pContent = NULL;
// 		free(del);
//         del = NULL;
// 		del = tmp;
// 	}
//     free(tmp);
//     tmp = NULL;
//     return (NULL);
// }