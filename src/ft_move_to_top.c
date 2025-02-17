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
#include <stdio.h>

static int	ft_get_min(t_list *list_a, int *idx)
{
	int		min;
	int		i;
	t_list	*ptr;

	min = list_a->val;
	i = 0;
	ptr = list_a;
	list_a = list_a->next;
	while (list_a)
	{
		if (list_a->val < min)
		{
			min = list_a->val;
		}
		list_a = list_a->next;
	}
	while (ptr && ptr->val != min)
	{
		i++;
		ptr = ptr->next;
	}
	*idx = i;
	return (min);
}
void	ft_move_to_top(t_list **list_a, int asize)
{
	t_operation	op;
	int			i;
	int			min;

	min = ft_get_min(*list_a, &i);
	if (i < asize / 2)
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
