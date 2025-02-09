/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_to_top.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:03:08 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/09 11:53:52 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef	void(*operation)(t_list **list_a);

void	ft_move_to_top(t_list **list_a, int id, int asize)
{
	operation	op;
	char		*str;

	if (id < asize / 2)
	{
		str = "ra\n";
		op = ra;
	}
	else
	{
		str = "rra\n";
		op = rra;
	}
	printf("ID ====> %d\n\n", id);
	while (*list_a && (*list_a)->val != id)
	{
		printf("%s", str);
		op(list_a);
	}
}
