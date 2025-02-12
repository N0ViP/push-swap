/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:01:57 by yjaafar           #+#    #+#             */
/*   Updated: 2025/01/15 15:27:55 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **lista)
{
	t_list	*tmp;

	write(1, "sa\n", 3);
	if (!lista || !*lista || !(*lista)->next)
		return ;
	tmp = *lista;
	*lista = (*lista)->next;
	tmp->next = (*lista)->next;
	(*lista)->next = tmp;
}
