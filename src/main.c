/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:31:31 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/12 17:24:59 by yjaafar          ###   ########.fr       */
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

static int	ft_fill_list_a(t_list **list_a, t_list *a, char **av, int ac)
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

int	main(int ac, char *av[])
{
	int				asize;
	static t_list	tmp[STACK_MAX];
	t_list			*list_a;
	t_list			*list_b;

	list_a = NULL;
	list_b = NULL;
	asize = ft_fill_list_a(&list_a, tmp, av + 1, ac - 1);
	if (asize == -1)
		return (write(2, "Error\n", 6));
	else if (asize == 0 || asize == 1)
		return (0);
	if (asize == 2)
	{
		if (tmp[0].val > tmp[1].val)
			write(1, "ra\n", 3);
		return (0);
	}
	ft_move_to_b(&list_a, &list_b, asize);
	ft_move_to_a(&list_a, &list_b);
	ft_move_to_top(&list_a, asize);
}
