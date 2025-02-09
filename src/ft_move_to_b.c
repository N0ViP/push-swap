/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:44:37 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/09 17:37:35 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_val(t_list *tmp, int asize)
{
	int		n;
	int		target;

	n = 0;
	target = tmp->val;
	tmp = tmp->next;
	while (tmp)
	{
		if (target < tmp->val)
			n++;
		tmp = tmp->next;
	}
	return (n <= (asize / 3));
}

void	ft_fix_list_a(t_list **list_a, int asize)
{
	int			if_ra;
	operation	op;
	t_list		*tmp;
	char		*str;

	if_ra = 0;
	tmp = *list_a;
	while (tmp && ft_check_val(tmp, asize))
	{
		tmp = tmp->next;
		if_ra++;
	}
	if (if_ra <= (asize / 2))
	{
		str = "ra\n";
		op = ra;
	}
	else
	{
		str = "rra\n";
		op = rra;
	}
	while (*list_a && ft_check_val(*list_a, asize))
	{
		op(list_a);
		printf("%s", str);
	}
}

void	ft_move_to_b(t_list **list_a, t_list **list_b, int asize)
{
	while (asize >= 3)
	{
		if (ft_check_val(*list_a, asize))
			ft_fix_list_a(list_a, asize);
		printf("pb\n");
		pb(list_b, list_a);
		asize--;
	}

	if (asize == 2 && (*list_a)->val > (*list_a)->next->val)
	{
		printf("ra\n");
		ra(list_a);
	}
}

