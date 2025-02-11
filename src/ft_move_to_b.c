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

int	ft_check_val(t_list *tmp, int val, int asize)
{
	int		n;

	n = 0;
	while (tmp)
	{
		if (val < tmp->val)
			n++;
		if (n >= (asize / 3))
				return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_rotate(t_list **list_a, int asize, int n)
{
	char		*str;
	operation	op;

	if (n <= (asize / 2))
	{
		str = "ra\n";
		op = ra;
	}
	else
	{
		str = "rra\n";
		op = rra;
	}
	while (*list_a && !ft_check_val(*list_a, (*list_a)->val, asize))
	{
		op(list_a);
		printf("%s", str);
	}
}

void	ft_fix_list_a(t_list **list_a, int asize)
{
	int		n;
	t_list	*tmp;

	n = 0;
	tmp = *list_a;
	while (tmp && !ft_check_val(*list_a, tmp->val, asize))
	{
		tmp = tmp->next;
		n++;
	}
	ft_rotate(list_a, asize, n);
}

void	ft_move_to_b(t_list **list_a, t_list **list_b, int asize)
{
	while (asize >= 3)
	{
		if (!ft_check_val(*list_a, (*list_a)->val, asize))
		{
			ft_fix_list_a(list_a, asize);
		}
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

