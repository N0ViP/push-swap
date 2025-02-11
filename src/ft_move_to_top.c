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
	int i;
	int min;
	int id;

	i = 0;
	id = 0;
	min = list_a->val;
	list_a->idx = i++;
	list_a = list_a->next;
	while (list_a)
	{
		if (list_a->val < min)
		{   
			id = i;
			min = list_a->val;
		}
		list_a->idx = i++;
		list_a = list_a->next;
	}
	return (id);
}

void	ft_move_to_top(t_list **list_a, int asize)
{
	operation	op;
	char		*str;
	int			id;

	id = ft_get_min(*list_a);
	if (id < asize / 2)
	{
		str = "ra\n";
		op = ra;
	}
	else
	{
		str = "rra\n";
		op = rra;
	}
	while (*list_a && (*list_a)->idx != id)
	{
		printf("%s", str);
		op(list_a);
	}
}
