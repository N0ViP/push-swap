/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 04:36:17 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/13 04:37:07 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char **av)
{
	long long	res;
	int			sign;

	res = 0;
	sign = -1 * (**av == 45) + (**av != 45);
	(*av) += (**av == 45 || **av == 43);
	if (!ft_isdigit(**av))
		return ((*av = NULL), 0);
	while (ft_isdigit(**av))
	{
		res = (res << 3) + (res << 1) + (**av & 0X0F);
		(*av)++;
		if (res > INT_MAX || (sign * res < INT_MIN))
			return ((*av = NULL), 0);
	}
	if (**av && !ft_isspace(**av))
		return ((*av = NULL), 0);
	return (res * sign);
}
