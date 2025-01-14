/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:23:19 by yjaafar           #+#    #+#             */
/*   Updated: 2025/01/14 18:26:48 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sb(t_list listb)
{
        int swap;

        if (!listb || !listb->next)
                return ;
        swap = listb->content;
        listb->content = listb->next->content;
        listb->next->content = swap;
}
