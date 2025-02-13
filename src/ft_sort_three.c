/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:56:58 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/11 15:12:02 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_list **list_a)
{
	int	first;
	int	scnd;
	int	third;

	first = (*list_a)->val;
	scnd = (*list_a)->next->val;
	third = (*list_a)->next->next->val;
	if ((first > scnd) && (first < third))
		sa(list_a);
	else if ((first < scnd) && (third < first))
		rra(list_a);
	else if ((first < third) && (scnd > third))
	{
		rra(list_a);
		sa(list_a);
	}
	else if ((first > third) && (scnd < third))
	{
		ra(list_a);
	}
	else if ((first > scnd) && (scnd > third))
	{
		sa(list_a);
		rra(list_a);
	}
}
