/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 09:02:50 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/09 13:23:39 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	ft_get_target(int n, t_list *list_a)
{
	int	target;

	target = INT_MAX;
	while (list_a)
	{
		if (list_a->val < target && n < list_a->val)
		{
			target = list_a->val;
		}
		list_a = list_a->next;
	}
	return (target);
}

void	ft_move_to_a(t_list **list_a, t_list **list_b, int asize)
{
	int	target;

	while (*list_b)
	{
		target = ft_get_target((*list_b)->val, *list_a);
		ft_move_element(list_a, list_b, target);
	}
}
