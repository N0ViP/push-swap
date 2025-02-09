/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 09:02:50 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/09 18:54:28 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
int	ft_get_target(int n, t_list *list_a)
{
	
}

int ft_get_move_a(int n, t_list **list_b->val)
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

int	ft_get_move_b(int n, t_list **list_b)
{
	int	val;

	val = INT_MIN;
	while (list_b)
	{
		if (list_b->val < n && val < list_b->val)
		{
			val = list_b->val;
		}
		list_b = list_b->next;
	}
	return (val);
}

int	ft_move_dep(int n, t_list *list_b)
{
	int	i;
	int	val;

	i = 0;
	val = ft_get_dep(n, list_b);
	while (list_b && list_b->val != val)
	{
		list_b = list_b->next;
		i++;
	}
	return (i);
}

void	ft_best_move(t_list **list_a, t_list **list_b, int asize)
{
	int	a;
	int	b;

	a = ft_move_target((*list_b)->val, list_a);
	b = ft_move_dep((*list_a)->val, list_b);
}
*/
void	ft_move_to_a(t_list **list_a, t_list **list_b, int asize)
{
//	int	target;

	while (*list_b)
	{
		ft_best_move(list_a, list_b);
		//ft_move_element(list_a, list_b, target);
	}
}
