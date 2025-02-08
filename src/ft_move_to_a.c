/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 09:02:50 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/08 10:15:51 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	ft_get_target(int n, t_list *list_a)
{
	int	target;

	target = list_a->val;
	list_a = list_a->next;
	while (list_a)
	{
		if (list_a->val > n && list_a->val < target)
			target = list_a;
		list_a = list_a->next;
	}
	return (target);
}

void	ft_move_element(int target, t_list **list_a)
{
	while ((*list_a)->val != target)
	{
		printf("ra\n");
		ra(list_a);
	}
}

void	ft_move_to_a(t_list **list_a, t_list **list_b, int asize)
{
	int	target;

	while (list_b)
	{
		target = ft_get_target(list_b->val, *list_a);
		ft_move_element(target, list_a);
	}
}
