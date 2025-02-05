/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:51:29 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/05 18:45:03 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_list **lista)
{
	t_list	*tmp;

	if (!lista || !*lista || !(*lista)->next)
		return ;
	tmp = *lista;
	*lista = (*lista)->next;
	tmp->next = NULL;
	while ((*lista)->next)
	{
		*lista = (*lista)->next;
	}
	(*lista)->next = tmp;
}
