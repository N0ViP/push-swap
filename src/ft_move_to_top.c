/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_to_top.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:03:08 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/09 13:16:38 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_min(t_list *list_a)
{
	int	min;

	min = list_a->val;
	list_a = list_a->next;
	while (list_a)
	{
		if (list_a->val < min)
		{
			min = list_a->val;
		}
		list_a = list_a->next;
	}
	return (min);
}

void	ft_move_to_top(t_list **list_a, int asize)
{
	t_operation	op;
	int			min;

	min = ft_get_min(*list_a);
	if (min < asize / 2)
	{
		op = ra;
	}
	else
	{
		op = rra;
	}
	while (*list_a && (*list_a)->val != min)
	{
		op(list_a);
	}
}
