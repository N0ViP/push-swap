#include "push_swap.h"

int	ft_one_arg(t_list **A, t_list *a, char *av)
{
	static int	aSize;
	long long	tmp;
	int			sign;

	while (*av)
	{
		sign = 0;
		while (*av == ' ' || (*av >= 9 && *av <= 13))
			av++;
		tmp = 0;
		sign = (*av == '-') * -1 + (*av != '-');
		av += (*av == '-' || *av == '+');
		while (*av >= 48 && *av <= 57)
		{
			tmp = (tmp << 3) + (tmp << 1) + (*av++ & 0X0F);
			if (tmp > 2147483647 || tmp <= -1)
				return (-1);
		}
		a[aSize].val = tmp * sign;
		a[aSize].idx = aSize;
		ft_lstadd_back(A, &a[aSize++]);
		if (*av && !ft_isspace(*av) && !ft_isdigit(*av))
			return (-1);
	}
	return (aSize);
}

int	ft_multi_args(t_list **A, t_list *a, char **av)
{
	int	i;
	int	aSize;

	i = 0;
	aSize = 0;
	while (av[i])
	{
		aSize = ft_one_arg(A, a, av[i]);
		if (aSize == -1)
			return (-1);
		i++;
	}
	return (aSize);
}

int	ft_fill_list_a(t_list **A, t_list *a, char **av, int ac)
{
	int	aSize;

	if (ac == 1)
		aSize = ft_one_arg(A, a, av[0]);
	else
		aSize = ft_multi_args(A, a, av);
	return (aSize);
}

int main(int ac, char *av[])
{
	int				aSize;
	static t_list	tmp[LIST_MAX];
	t_list			*A;

	A = NULL;
	if (ac == 1 || (ac = 2 && !av[1][0]))
		return (1);
	aSize = ft_fill_list_a(&A, tmp, av + 1, ac - 1);
	if (aSize == -1)
		return (printf("Error\n"));
	while (A)
	{
		printf("a[%d] = %d\n", A->idx, A->val);
		A = A->next;
	}
}
