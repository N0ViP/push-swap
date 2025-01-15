/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:51:29 by yjaafar           #+#    #+#             */
/*   Updated: 2025/01/15 15:07:20 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap"

void ra(t_list **lista)
{
	t_list	*tmp;

	if (!list || !*lista || !*lista-next)
		return ;
	tmp = *lista;
	*lista = *lista->next;
	tmp->next = NULL;
	while (*lista->next)
	{
		*lista = *lista->next;
	}
	*lista->next = tmp;
}
