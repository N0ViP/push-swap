/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 03:02:53 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/12 08:48:09 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_move_b_to_top(t_list *list_b, int val)
{
	int	m;

	m = 0;
	while (list_b->val != val)
	{
		list_b = list_b->next;
		m++;
	}
	return (m);
}

static int	ft_move_a_to_top(t_list *list_a, t_stock *stock, int val)
{
	int		n;
	int		i;
	t_list	*tmp;

	i = 0;
	n = INT_MAX;
	tmp = list_a;
	while (tmp)
	{
		if (val < tmp->val && tmp->val < n)
			n = tmp->val;
		tmp = tmp->next;
	}
	stock->tmp_target = n;
	while (list_a && list_a->val != n)
	{
		list_a = list_a->next;
		i++;
	}
	return (i);
}

static int	ft_get_moves(t_list *list_a, t_list *list_b,
	t_stock *stock, int val)
{
	int	n;
	int	m;

	n = ft_move_a_to_top(list_a, stock, val);
	m = ft_move_b_to_top(list_b, val);
	if (stock->asize / 2 < n)
	{
		stock->tmp_amove = 1;
		n = stock->asize - n;
	}
	else
		stock->tmp_amove = 0;
	if (stock->bsize / 2 < m)
	{
		stock->tmp_bmove = 1;
		m = stock->bsize - m;
	}
	else
		stock->tmp_bmove = 0;
	if (stock->tmp_bmove != stock->tmp_amove)
		return (m + n);
	if (m > n)
		return (m);
	return (n);
}

static void	ft_fix_list(t_list **list_a, t_list **list_b, t_stock *stock)
{
	t_list	*tmp;
	int		move;
	int		best;

	tmp = *list_b;
	best = INT_MAX;
	while (tmp)
	{
		move = ft_get_moves(*list_a, *list_b, stock, tmp->val);
		if (move < best)
		{
			best = move;
			stock->target = stock->tmp_target;
			stock->num = tmp->val;
			stock->amove = stock->tmp_amove;
			stock->bmove = stock->tmp_bmove;
		}
		tmp = tmp->next;
	}
	ft_move(list_a, list_b, stock);
}

void	ft_move_to_a(t_list **list_a, t_list **list_b)
{
	t_stock	stock;

	stock.asize = ft_list_len(*list_a);
	stock.bsize = ft_list_len(*list_b);
	while (*list_b)
	{
		ft_fix_list(list_a, list_b, &stock);
		pa(list_a, list_b);
		stock.bsize--;
		stock.asize++;
	}
}
