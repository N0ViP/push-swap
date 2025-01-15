/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:23:19 by yjaafar           #+#    #+#             */
/*   Updated: 2025/01/15 15:27:35 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list **listb)
{
	t_list  *tmp;

	if (!listb || !*listb || !(*listb)->next)
		return ;
	tmp = *listb;
	*listb = (*listb)->next;
	tmp->next = (*listb)->next;
	(*listb)->next = tmp;
}
