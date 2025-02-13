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

void	ft_move(t_list **a, t_list **b, t_stock *stock)
{
	t_operation	a_op;
	t_operation	b_op;

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
			while ((*a)->val != stock->target && (*b)->val != stock->num)
				rrr(a, b);
		else
			while ((*a)->val != stock->target && (*b)->val != stock->num)
				rr(a, b);
	}
	while ((*a)->val != stock->target)
		a_op(a);
	while ((*b)->val != stock->num)
		b_op(b);
}
