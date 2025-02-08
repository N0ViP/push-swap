/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 09:02:50 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/08 17:58:18 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
int	ft_get_target(int n, t_list *list_a)
{
	int	target;

	while (list_a->val < n)
	{
		list_a = list_a->next;
	}
	target = list_a->val;
	list_a = list_a->next;
	while (list_a)
	{
		if (list_a->val < target)
		{
			target = list_a->val;
		}
		list_a = list_a->next;
	}
	return (target);
}

void	ft_move_element(t_list **list_a, t_list **list_b, int target)
{
	while ((*list_a)->val != target)
	{
		printf("ra\n");
		ra(list_a);
	}
	printf("pa\n");
	pa(list_a, list_b);
}
*/
void ft_get_large(t_list **list_b)
{
	t_list *tmp = *list_b;
	int max = tmp->val;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->val > max)
			max = tmp->val;
		tmp = tmp->next;
	}

	while (*list_b && (*list_b)->val != max)	//?
	{
		printf("rb\n");
		rb(list_b);
	}
}

void	ft_move_to_a(t_list **list_a, t_list **list_b, int asize)
{
	int	target;

	while (*list_b)
	{
		ft_get_large(list_b);
		printf("pa\n");
		pa(list_a, list_b);
		//target = ft_get_target((*list_b)->val, *list_a);
		//ft_move_element(list_a, list_b, target);
	}
}
