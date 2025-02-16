/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 04:01:21 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/15 04:10:48 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_exist(t_list *a, int tmp, int asize)
{
	int	i;

	i = 0;
	while (i < asize)
	{
		if (a[i].val == tmp)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_one_arg(t_list *a, char *av)
{
	static int	asize;
	int			tmp;

	while (ft_isspace(*av))
		av++;
	if (!*av)
		return (-1);
	while (*av)
	{
		while (ft_isspace(*av))
			av++;
		if (!*av)
			return (asize);
		tmp = ft_atoi(&av);
		if (!av || ft_check_exist(a, tmp, asize))
			return (-1);
		a[asize].val = tmp;
		a[asize].idx = asize;
		asize++;
	}
	return (asize);
}

static int	ft_multi_args(t_list *a, char **av)
{
	int	i;
	int	asize;

	i = 0;
	asize = 0;
	while (av[i])
	{
		asize = ft_one_arg(a, av[i]);
		if (asize == -1)
			return (-1);
		i++;
	}
	return (asize);
}

static int	ft_fill_list_a(t_list **list_a, t_list *a, char **av)
{
	int	asize;
	int	i;
	int	j;

	asize = ft_multi_args(a, av);
	i = asize - 1;
	while (i >= 0)
		ft_lstadd_front(list_a, &a[i--]);
	i = 0;
	while (i < asize - 1)
	{
		j = i + 1;
		while (j < asize)
		{
			if (a[i].val > a[j].val)
				return (asize);
			j++;
		}
		i++;
	}
	if (asize == -1)
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	static t_list	tmp[STACK_MAX];
	t_list			*list_a;
	t_list			*list_b;
	int				asize;

	if (ac != 2)
		return (1);
	list_a = NULL;
	list_b = NULL;
	asize = ft_fill_list_a(&list_a, tmp, av + 1);
	if (asize == -1)
		return (write(2, "Error\n", 6), 1);
	ft_take_op(&list_a, &list_b);
	if (ft_check_list(list_a, asize))
		return (write(1, "KO\n", 3), 1);
	return (write(1, "OK\n", 3), 0);
}
