/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:45:08 by yjaafar           #+#    #+#             */
/*   Updated: 2025/01/15 15:08:22 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap"

void	rb(t_list **listb)
{
	t_list  *tmp;

	if (!list || !*listb|| !*listb-next)
		return ;
	tmp = *listb;
	*listb = *listb->next;
	tmp->next = NULL;
	while (*listb->next)
	{
		*listb = *listb->next;
	}
	*listb->next = tmp;
}
