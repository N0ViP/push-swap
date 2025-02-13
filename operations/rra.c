/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:12:30 by yjaafar           #+#    #+#             */
/*   Updated: 2025/01/15 22:07:54 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **lista)
{
	t_list	*tmp;
	t_list	*ptr;

	write(1, "rra\n", 4);
	if (!lista || !*lista || !(*lista)->next)
		return ;
	ptr = *lista;
	while (ptr->next->next)
	{
		ptr = ptr->next;
	}
	tmp = *lista;
	*lista = ptr->next;
	ptr->next = NULL;
	(*lista)->next = tmp;
}
