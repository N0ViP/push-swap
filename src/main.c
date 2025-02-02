#include "push_swap.h"

int	ft_ascii_to_int(char** av)
{
	long long	res;
	int			sign;

	res = 0;
	sign = -1 * (**av == 45) + (**av != 45);
	(*av) += (**av == 45 || **av == 43);
	if (ft_isspace(**av) || **av == 45 || **av == 43)
			return ((*av = NULL), 0);
	while (**av >= 48 && **av <= 57)
	{
		res = (res << 3) + (res << 1) + (**av & 0X0F);
		(*av)++;
		if (res > MAX_INT || res < 0)
				return ((*av = NULL), 0);
	}
	if (**av && !ft_isspace(**av))
			return ((*av = NULL), 0);
	return (res * sign);
}

int	ft_one_arg(t_list **A, t_list *a, char *av)
{
	static int	aSize;
	int			tmp;

	while (ft_isspace(*av))
		av++;
	while (*av)
	{
		tmp = ft_ascii_to_int(&av);
		if (!av)
				return (-1);
		a[aSize].val = tmp;
		a[aSize].idx = aSize;
		ft_lstadd_back(A, &a[aSize++]);
		while (ft_isspace(*av))
			av++;
	}
	return (aSize);
}

int	ft_multi_args(t_list **A, t_list *a, char **av)
{
	int	i;
	int	aSize;

	i = 0;
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
		return (write(2, "Error\n", 6));
	ft_move_to_b(A);

}
