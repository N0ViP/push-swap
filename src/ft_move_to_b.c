/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 06:13:55 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/11 16:03:52 by yjaafar          ###   ########.fr       */
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
		if ((asize / 3) < n)
			return (1);
		list_a = list_a->next;
	}
	return (0);
}

int	ft_get_moves(int val, t_list *list_a, int asize)
{
	int	i;

	i = 0;
	while (list_a && list_a->val != val)
	{
		i++;
		list_a = list_a->next;
	}
	if (i <= asize / 2)
		return (i);
	return (asize - i);
}

void	ft_rotate_a(t_list **list_a, int val, int asize)
{
	t_list		*tmp;
	int			i;
	operation	op;
	char		*str;

	i = 0;
	tmp = *list_a;
	while (tmp && tmp->val != val)
	{
		i++;
		tmp = tmp->next;
	}
	if (i <= asize / 2)
	{
		op = ra;
		str = "ra\n";
	}
	else
	{
		op = rra;
		str = "rra\n";
	}
	while (*list_a && (*list_a)->val != val)
	{
		printf("%s", str);
		op(list_a);
	}
}

void	ft_fix_list_a(t_list **list_a, int asize)
{
	t_list	*tmp;
	int		best;
	int		moves;
	int		val;

	best = INT_MAX;
	tmp = *list_a;
	while (tmp)
	{
		moves = ft_get_moves(tmp->val, *list_a, asize);
		if (check_if_valid(*list_a, tmp->val, asize) && moves <= best)
		{
			val = tmp->val;
			best = moves;
		}
		tmp = tmp->next;
	}
	ft_rotate_a(list_a, val, asize);
}

void	ft_move_to_b(t_list **list_a, t_list **list_b, int asize)
{
	while (asize > 3)
	{
		if (!check_if_valid(*list_a, (*list_a)->val, asize))
			ft_fix_list_a(list_a, asize);
		printf("pb\n");
		pb(list_b, list_a);
		asize--;
	}
	sort_3(list_a);
}
