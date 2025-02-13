/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 04:33:54 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/13 04:34:26 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move(t_list **list_a, t_list **list_b, t_stock *stock)
{
	operation	a_op;
	operation	b_op;

	if (stock->amove)
		a_op = rra;
	else
		a_op = ra;
	if (stock->bmove)
		b_op = rrb;
	else
		b_op = rb;
	if (stock->amove == stock->bmove)
	{
		if (stock->amove == 1)
			while ((*list_a)->val != stock->target && (*list_b)->val != stock->num)
				rrr(list_a, list_b);
		else
			while ((*list_a)->val != stock->target && (*list_b)->val != stock->num)
				rr(list_a, list_b);

	}
	while ((*list_a)->val != stock->target)
		a_op(list_a);
	while ((*list_b)->val != stock->num)
		b_op(list_b);
}
