/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:45:08 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/08 17:44:51 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_list **list_b)
{
	t_list  *tmp;
	t_list	*ptr;

	write(1, "rb\n", 3);
	if (!list_b || !*list_b|| !(*list_b)->next)
		return ;
	tmp = *list_b;
	*list_b = (*list_b)->next;
	ptr = *list_b;
	tmp->next = NULL;
	while (ptr->next)
	{
		ptr = ptr->next;
	}
	ptr->next = tmp;
}
