#include "push_swap.h"

void	ft_best_move(t_list **list_a, t_list **list_b)
{
	int	a_val;
	int	b_val;
	int	a = if_rotat_a((*list_b)->val, &a_val, *list_a);
	int	b = if_rotat_b((*list_a)->val, &b_val, *list_b);

	if (a < b)
	{
		ft_rotat_a(list_a, a_val);
	}
	else
	{
		ft_rotat_b(list_b, b_val);
	}
}
