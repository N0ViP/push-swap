/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:29:33 by yjaafar           #+#    #+#             */
/*   Updated: 2025/01/14 18:49:12 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_list lista, t_list listb)
{
	t_list tmp;
	if (!listb)
		return ;
	tmp = lista;
	lista = listb;
	listb = listb->next;
	lista->next = tmp;
}
