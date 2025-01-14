/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:01:57 by yjaafar           #+#    #+#             */
/*   Updated: 2025/01/14 18:22:56 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_list lista)
{
	int swap;

	if (!lista || !lista->next)
		return ;
	swap = lista->content;
	lista->content = lista->next->content;
	lista->next->content = swap;
}
