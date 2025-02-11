/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 06:13:55 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/11 14:24:53 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_valid(t_list *list_a, int val, int asize)
{
	int	n;

	n = 0;
	while (list_a)
	{
		if (val < list_a->val)
			n++;
		list_a = list_a->next;
	}
	return ((asize / 3) < n);
}

void	ft_fix_list_a(t_list **list_a, int asize)
{
	t_list *tmp;

	tmp = *list_a;
	while (tmp)
	{
		
	}
}

void	ft_move_to_b(t_list **list_a, t_list **list_b, int asize)
{
	while (asize >= 3)
	{
		if (!check_if_valid(*list_a, (*list_a)->val, asize))
			ft_fix_list_a(list_a, asize);
		printf("pb\n");
		pb(list_b, list_a);
		asize--;
	}
}
