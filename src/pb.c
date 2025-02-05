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

void	pb(t_list **listb, t_list **lista)
{
	t_list *tmp;
	tmp = *listb;
	*listb = *lista;
	*lista = (*lista)->next;
	(*listb)->next = tmp;
}
