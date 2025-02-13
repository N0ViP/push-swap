/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:40:40 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/05 18:56:51 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **list_b, t_list **list_a)
{
	t_list	*tmp;

	write(1, "pb\n", 3);
	if (!list_a || !*list_a)
		return ;
	tmp = *list_b;
	*list_b = *list_a;
	*list_a = (*list_a)->next;
	(*list_b)->next = tmp;
}
