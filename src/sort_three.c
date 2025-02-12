/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:56:58 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/11 15:12:02 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_sort_three(t_list **a)
{
    int    first;
    int    scnd;
    int    third;

    first = (*a)->val;
    scnd = (*a)->next->val;
    third = (*a)->next->next->val;
    if ((first > scnd) && (first < third))
        sa(a);
    else if ((first < scnd) && (third < first))
        rra(a);
    else if ((first < third) && (scnd > third))
    {
        rra(a);
        sa(a);
    }
    else if ((first > third) && (scnd < third))
	{
        ra(a);
	}
    else if ((first > scnd) && (scnd > third))
    {
        sa(a);
        rra(a);
    }
}
