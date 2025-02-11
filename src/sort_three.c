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

void    sort_3(t_list **a)
{
    int    first;
    int    scnd;
    int    third;

    first = (*a)->val;
    scnd = (*a)->next->val;
    third = (*a)->next->next->val;
    if ((first > scnd) && (first < third))
	{
		printf("sa\n");
        sa(a);
	}
    else if ((first < scnd) && (third < first))
	{
		printf("rra\n");
        rra(a);
	}
    else if ((first < third) && (scnd > third))
    {
		printf("rra\nsa\n");
        rra(a);
        sa(a);
    }
    else if ((first > third) && (scnd < third))
	{
		printf("ra\n");
        ra(a);
	}
    else if ((first > scnd) && (scnd > third))
    {
		printf("sa\nrra\n");
        sa(a);
        rra(a);
    }
}
