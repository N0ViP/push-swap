#include "push_swap.h"

int	ft_one_arg(t_list *a, char *av)
{
	static int	aSize;
	long long	tmp;

	tmp = 0;
	while (*av)
	{
		while (*av == ' ' || (*av >= 9 && *av <= 13))
			av++;
		while (*av >= 48 && *av <= 57)
		{
			tmp = (tmp << 3) + (tmp << 1) + (*av++ & 0X0F);
			if (tmp > 2147483647 || tmp < -2147483648)
				return (-1);
		}
		a[aSize].val = tmp;
		a[aSize].idx = aSize++;
		if (*av && !ft_isspace(*av) && !ft_isdigit(*av))
			return (-1);
	}
	return (aSize);
}

int	ft_multi_args(t_list *a, char **av)
{
	int	i;
	int	aSize;

	i = 0;
	aSize = 0;
	while (av[i])
	{
		aSize = ft_one_arg(a, av[i]);
		if (aSize == -1)
			return (-1);
		i++;
	}
	return (aSize);
}

int	ft_fill_list_a(t_list *a, char **av, int ac)
{
	int	aSize;

	if (ac == 1)
		aSize = ft_one_arg(a, av[0]);
	else
		aSize = ft_multi_args(a, av);
	return (aSize);
}

int main(int ac, char *av[])
{
	int		aSize;
	t_list	a[LIST_MAX];
	t_list	b[LIST_MAX];

	if (ac == 1 || (ac = 2 && !av[1][0]))
		return (1);
	aSize = ft_fill_list_a(&a, av + 1, ac - 1);
	for (int i = 0; i < aSize; i++)
	{
		printf("a[%d] = %d\n", i, a[i].val);
	}
}
