/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 09:02:50 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/10 18:42:06 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	if_rotat_a(int val, int *tmp_target, t_list *list_a)
{
	int		n;
	int		a;
	t_list	*tmp;

	n = INT_MAX;
	a = 0;
	tmp = list_a;
	while (list_a)
	{
		if (val < list_a->val && list_a->val < n)
		{
			n = list_a->val;
		}
		list_a = list_a->next;
	}
	*tmp_target = n;
	while (tmp && tmp->val != n)
	{
		a++;
		tmp = tmp->next;
	}
	return (a);
}

int	move_ab_to_top(int val, t_list *list_b, t_list *list_a, t_stock *stock)
{
	int	n;
	int	m;

	n = 0;
	while (list_b && list_b->val != val)
	{
		n++;
		list_b = list_b->next;
	}
	stock->tmp_num = val;
	m = if_rotat_a(val, &(stock->tmp_target), list_a);
	if (n > m)
		return (n);
	return (m);
}

void	ft_move_target_and_num(t_list **list_a, t_list **list_b, t_stock *stock)
{
	while ((*list_a && (*list_a)->val != stock->target)
		&& (*list_b && (*list_b)->val != stock->num))
	{
		printf("rr\n");
		rr(list_a, list_b);
	}
	while (*list_a && (*list_a)->val != stock->target)
	{
		printf("ra\n");
		ra(list_a);
	}
	while (*list_b && (*list_b)->val != stock->num)
	{
		printf("rb\n");
		rb(list_b);
	}
}

void	ft_best_move(t_list **list_a, t_list **list_b)
{
	t_list	*ptr;
	t_stock	stock;
	int		moves;
	int		best;

	best = INT_MAX;
	ptr = *list_b;
	while (ptr)
	{
		moves = move_ab_to_top(ptr->val, *list_b, *list_a, &stock);
		if (moves <= best)
		{
			best = moves;
			stock.target = stock.tmp_target;
			stock.num = stock.tmp_num;
		}
		ptr = ptr->next;
	}
	ft_move_target_and_num(list_a, list_b, &stock);
}

void	ft_move_to_a(t_list **list_a, t_list **list_b, int asize)
{
	while (*list_b)
	{
		ft_best_move(list_a, list_b);
		printf("pa\n");
		pa(list_a, list_b);
	}
}
