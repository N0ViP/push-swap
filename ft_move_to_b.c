#include "push_swap.h"

int	ft_check_list_a(t_list *list_a, int val, int asize)
{
	int	n;

	n = 0;
	while (list_a)
	{
		if (list_a->val < val)
		{
			n++;
		}
		list_a = list_a->next;
	}
	if (n <= (asize / 3))
			return (n);
	return (-1);
}

void	ft_fix_list_a(t_list **list_a, int asize)
{
	int			n;
	t_list		*tmp;
	char		*str;
	operation	op;
	int j = 0;

	tmp = *list_a;
	while (tmp)
	{
		n = ft_check_list_a(*list_a, tmp->val, asize);
		if (n != -1)
			break ;
		j++;
		tmp = tmp->next;
	}
	if (j < (asize / 2))
	{
		str = "ra\n";
		op = ra;
	}
	else
	{
		str = "rra\n";
		op = rra;
	}
	while (*list_a && (*list_a)->val != tmp->val)
	{
		printf("%s", str);
		op(list_a);
	}
}

void	ft_move_to_b(t_list **list_a, t_list **list_b, int asize)
{
	while (2 < asize)
	{
		if (ft_check_list_a(*list_a, (*list_a)->val, asize) == -1)
			ft_fix_list_a(list_a, asize);
		printf("pb\n");
		pb(list_b, list_a);
		asize--;
	}

	if (asize == 2 && (*list_a)->val > (*list_a)->next->val)
	{
		printf("ra\n");
		ra(list_a);
	}
}
