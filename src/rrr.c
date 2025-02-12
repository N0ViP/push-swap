/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:13:56 by yjaafar           #+#    #+#             */
/*   Updated: 2025/01/15 22:15:07 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	r_r(t_list **list)
{
	t_list	*tmp;
	t_list	*ptr;

	if (!list || !*list || !(*list)->next)
		return ;
	ptr = *list;
	while (ptr->next->next)
	{
		ptr = ptr->next;
	}
	tmp = *list;
	*list = ptr->next;
	ptr->next = NULL;
	(*list)->next = tmp;
}

void	rrr(t_list **list_a, t_list **list_b)
{
	write(1, "rrr\n", 4);
	r_r(list_a);
	r_r(list_b);
}
