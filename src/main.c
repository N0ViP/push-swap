#include "push_swap.h"

int	ft_fill_list_a(t_list *a, char **av)
{
	long	tmp;
	int	i;

	i = 0;
	while (av[i])
	{
		tmp = ft_atol(av[i]);
		if (tmp > MAX_INT || tmp < MIN_INT || av[i])
			return (-1);
		av[i].val = tmp;
		av[i].idx = i;
		i++;
	}

	return (0);
}

int main(int ac, char *av[])
{
	t_list	a[LIST_MAX];
	t_list	b[LIST_MAX];

	if (ac == 1 || (ac = 2 && !av[1][i]))
		return (1);
	if (ac == 2)
		av = ft_split(av[1]);
	ft_fill_list_a(&a, av + 1);
	ft_move_to_b();
	ft_move_to_a();
}
