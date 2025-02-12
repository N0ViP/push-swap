/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 03:02:53 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/12 07:05:25 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    ft_move(t_list **list_a, t_list **list_b, t_stock *stock);

static int	ft_list_size(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

static int	ft_move_b_to_top(t_list *list_b, int val)
{
	int	n;

	n = 0;
	while (list_b && list_b->val != val)
	{
		list_b = list_b->next;
		n++;
	}
	return (n);
}

static int	ft_move_a_to_top(t_list *list_a, int *target, int val)
{
	int		n;
	int		i;
	t_list	*tmp;

	i = 0;
	n = INT_MAX;
	tmp = list_a;
	while (tmp)
	{
		if (val < n && n < tmp->val)
			n = tmp->val;
		tmp = tmp->next;
	}
	*target = n;
	while (list_a && list_a->val != n)
	{
		list_a = list_a->next;
		i++;
	}
	return (i);
}

static int	ft_get_moves(t_list *list_a, t_list *list_b, t_stock *stock, int val)
{
	int	n;
	int	m;

	n = ft_move_a_to_top(list_a, &(stock->tmp_target), val);
	m = ft_move_b_to_top(list_b, val);
	if (stock->asize / 2 < n)
		n = stock->asize - n;
	if (stock->bsize / 2 < m)
		m = stock->asize - m;
	return (m + n);
}

static void	ft_move_ab_to_top(t_list **list_a, t_list **list_b, t_stock *stock)
{
	int	n;
	int	m;

	n = ft_move_a_to_top(*list_a, &(stock->target), stock->num);
	m = ft_move_b_to_top(*list_a, stock->num);
	stock->amove = stock->bsize / 2 < n;
	stock->bmove = stock->bsize / 2 < m;
	ft_move(list_a, list_b, stock);
}

static void	ft_move(t_list **list_a, t_list **list_b, t_stock *stock)
{
	if (stock->amove == stock->bmove)
	{
		if (stock->amove == 1)
		{
			while ((*list_a)->val != stock->target && (*list_b)->val != stock->num)
			{
				printf("rrr\n");
				rrr(list_a, list_b);
			}
			while ((*list_a)->val != stock->target)
			{
				printf("rra\n");
				rra(list_a);
			}
			while ((*list_b)->val != stock->num)
			{
				printf("rrb\n");
				rrb(list_b);
			}
		}
		else
		{
			while ((*list_a)->val != stock->target && (*list_b)->val != stock->num)
			{
				printf("rr\n");
				rr(list_a, list_b);
			}
			while ((*list_a)->val != stock->target)
			{
				printf("ra\n");
				ra(list_a);
			}
			while ((*list_b)->val != stock->num)
			{
				printf("rb\n");
				rb(list_b);
			}
		}
	}
	else
	{
		if (stock->amove == 1)
		{
			while ((*list_a)->val != stock->target)
			{   
				printf("rra\n");
				rra(list_a);
			}
			while ((*list_b)->val != stock->num)
			{   
				printf("rb\n");
				rb(list_b);
			}
		}
		else
		{
			while ((*list_a)->val != stock->target)
			{
				printf("ra\n");
				ra(list_a);
			}
			while ((*list_b)->val != stock->num)
			{
				printf("rrb\n");
				rrb(list_b);
			}
		}
	}
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
		if (move <= best)
		{
			best = move;
			stock->target = stock->tmp_target;
			stock->num = tmp->val;
		}
		tmp = tmp->next;
	}
	ft_move_ab_to_top(list_a, list_b, stock);
}

void	ft_move_to_a(t_list **list_a, t_list **list_b)
{
	t_stock	stock;

	stock.asize = ft_list_size(*list_a);
	stock.bsize = ft_list_size(*list_b);
	while (*list_b)
	{
		ft_fix_list(list_a, list_b, &stock);
		printf("pa\n");
		pa(list_a, list_b);
		stock.bsize--;
		stock.bsize++;
	}
}
