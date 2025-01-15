/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:08:04 by yjaafar           #+#    #+#             */
/*   Updated: 2025/01/15 22:12:32 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_list **listb)
{
	t_list	*tmp;
	t_list	*ptr;

	if (!listb || !*listb || !(*listb)->next)
		return ;
	ptr = *listb;
	while (ptr->next->next)
	{
		ptr = ptr->next;
	}
	tmp = *listb;
	*listb = ptr->next;
	ptr->next = NULL;
	(*listb)->next = tmp;
}
