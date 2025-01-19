/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:26:17 by yjaafar           #+#    #+#             */
/*   Updated: 2025/01/19 05:06:22 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	register long long	res;
	int					sign;

	sign = 0;
	while (*s && ((*s >= '\t' && *s <= '\r') || *s == ' '))
		s++;
	sign = (*s == '-');
	s += (*s == '-' || *s == '+');
	if (!*s || (*s == '0' && !*(s + 1)))
		return (0);
	res = 0;
	while (*s >= '0' && *s <= '9')
	{
		res = (res << 3) + (res << 1) + (*s++ & 0X0F);
		if (res < 0)
		{
			if (sign != 1)
				return (-1);
			return (0);
		}
	}
	if (sign == 1)
		res = -res;
	return ((int) res);
}
