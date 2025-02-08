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

void	rb(t_list **listb)
{
	t_list  *tmp;
	t_list	*ptr;

	if (!listb || !*listb|| !(*listb)->next)
		return ;
	tmp = *listb;
	*listb = (*listb)->next;
	tmp->next = NULL;
	ptr = *listb;
	while (ptr->next)
	{
		ptr = ptr->next;
	}
	ptr->next = tmp;
}
