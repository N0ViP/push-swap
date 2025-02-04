/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:31:31 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/03 20:01:20 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ascii_to_int(char **av)
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
		if (res > MAX_INT || (sign * res < MIN_INT))
			return ((*av = NULL), 0);
	}
	if (**av && !ft_isspace(**av))
		return ((*av = NULL), 0);
	return (res * sign);
}

int	ft_one_arg(t_list **list_a, t_list *a, char *av)
{
	static int	asize;
	int			tmp;

	if (!*av)
		return (-1);
	while (*av)
	{
		while (ft_isspace(*av))
			av++;
		if (!*av)
			return (asize);
		tmp = ft_ascii_to_int(&av);
		if (!av)
			return (-1);
		a[asize].val = tmp;
		a[asize].idx = asize;
		ft_lstadd_back(list_a, &a[asize++]);
	}
	return (asize);
}

int	ft_multi_args(t_list **list_a, t_list *a, char **av)
{
	int	i;
	int	asize;

	i = 0;
	asize = 0;
	while (av[i])
	{
		asize = ft_one_arg(list_a, a, av[i]);
		if (asize == -1)
			return (-1);
		i++;
	}
	return (asize);
}

int	ft_fill_list_a(t_list **list_a, t_list *a, char **av, int ac)
{
	int	asize;

	if (ac == 1)
		asize = ft_one_arg(list_a, a, av[0]);
	else
		asize = ft_multi_args(list_a, a, av);
	return (asize);
}

int	main(int ac, char *av[])
{
	int				asize;
	static t_list	tmp[LIST_MAX];
	t_list			*list_a;

	list_a = NULL;
	asize = ft_fill_list_a(&list_a, tmp, av + 1, ac - 1);
	if (asize == -1)
		return (write(2, "Error\n", 6));
	while (list_a)
	{
		printf("list_a[%d] = %d\n", list_a->idx, list_a->val);
		list_a = list_a->next;
	}
}
