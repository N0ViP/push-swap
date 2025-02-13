/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:54:27 by yjaafar           #+#    #+#             */
/*   Updated: 2025/01/15 15:55:52 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	r(t_list **list)
{
	t_list	*tmp;
	t_list	*ptr;

	if (!list || !*list || !(*list)->next)
		return ;
	tmp = *list;
	*list = (*list)->next;
	ptr = *list;
	tmp->next = NULL;
	while (ptr->next)
	{
		ptr = ptr->next;
	}
	ptr->next = tmp;
}

void	rr(t_list **list_a, t_list **list_b)
{
	write(1, "rr\n", 3);
	r(list_a);
	r(list_b);
}
