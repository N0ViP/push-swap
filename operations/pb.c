/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:40:40 by yjaafar           #+#    #+#             */
/*   Updated: 2025/01/15 15:51:53 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **listb, t_list **lista)
{
	t_list *tmp;
	if (!listb || *lista || !*lista)
		return ;
	tmp = *listb;
	*listb = *lista;
	*lista = (*lista)->next;
	(*listb)->next = tmp;
}
