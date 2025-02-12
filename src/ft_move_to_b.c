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

int	ft_check_val(t_list *list_a, int asize)
{
	int		n;
	int		target;
	t_list	*tmp;

	n = 0;
	tmp = list_a;
	target = tmp->val;
	tmp = tmp->next;
	while (tmp)
	{
		if (target < tmp->val)
			n++;
		tmp = tmp->next;
	}
	return (n);
}

void	ft_move_to_b(t_list **list_a, t_list **list_b, int asize)
{
	while (asize > 3)
	{
		while (ft_check_val(*list_a, asize) < (asize / 2))
		{
			ra(list_a);
		}
		pb(list_b, list_a);
		asize--;
	}
	ft_sort_three(list_a);
}