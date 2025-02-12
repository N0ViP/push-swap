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

int	ft_check_exist(t_list *a, int tmp, int asize)
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

int	ft_one_arg(t_list *a, char *av)
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
		tmp = ft_atoi(&av);
		if (!av || ft_check_exist(a, tmp, asize))
			return (-1);
		a[asize].val = tmp;
		a[asize].idx = asize;
		asize++;
	}
	return (asize);
}

int	ft_multi_args(t_list *a, char **av)
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

int	ft_fill_list_a(t_list **list_a, t_list *a, char **av, int ac)
{
	int	asize;
	int	i;

	if (ac == 1)
		asize = ft_one_arg(a, av[0]);
	else
		asize = ft_multi_args(a, av);
	i = asize - 1;
	while (i >= 0)
	{
		ft_lstadd_front(list_a, &a[i]);
		i--;
	}
	return (asize);
}

int	main(int ac, char *av[])
{
	int				asize;
	static t_list	tmp[STACK_MAX];
	t_list			*list_a;
	t_list			*list_b;
	t_list *t;

	list_a = NULL;
	list_b = NULL;
	asize = ft_fill_list_a(&list_a, tmp, av + 1, ac - 1);
	if (asize == -1)
		return (write(2, "Error\n", 6));
	else if (asize == 0 || asize == 1)
		return (0);
	//printf("\n\n\n");
	ft_move_to_b(&list_a, &list_b, asize);
	/*t = list_a;
	while (t)
	{

		printf("list_a[%d] = %d\n", t->idx, t->val);
		t = t->next;
	}
	printf("\n\n\n");

	t = list_b;
	while (t)
	{
		printf("list_b[%d] = %d\n", t->idx, t->val);
		t = t->next;
	}*/
	ft_move_to_a(&list_a, &list_b);
	ft_move_to_top(&list_a, asize);
	/*printf("\n\n\n");
	while (list_a)
	{
		printf("list_a[%d] = %d\n", list_a->idx, list_a->val);
		list_a = list_a->next;
	}*/

}
