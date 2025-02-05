/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:44:37 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/05 18:47:49 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_val(t_list **list_a, int asize)
{
	int		n;
	int		target;
	t_list	*tmp;

	n = 0;
	tmp = *list_a;
	target = tmp->val;
	tmp = tmp->next;
	while (tmp)
	{
		if (target < tmp->val)
			n++;
		tmp = tmp->next;
	}
/*	if (n > asize / 3)
	{
		printf("ra\n");
		return (ra(list_a), ft_check_val(list_a, asize));
	}*/
	return (n);
}

void	ft_move_to_b(t_list **list_a, t_list **list_b, int asize)
{
	while (asize >= 3)
	{
		while (ft_check_val(list_a, asize) > (asize / 3))
		{
			printf("ra\n");
			ra(list_a);
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
