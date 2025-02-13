/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:51:29 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/05 18:45:03 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **list_a)
{
	t_list	*tmp;
	t_list	*ptr;

	write(1, "ra\n", 3);
	if (!list_a || !*list_a || !(*list_a)->next)
		return ;
	tmp = *list_a;
	*list_a = (*list_a)->next;
	ptr = *list_a;
	tmp->next = NULL;
	while (ptr->next)
	{
		ptr = ptr->next;
	}
	ptr->next = tmp;
}
