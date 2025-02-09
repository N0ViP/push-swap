#include "push_swap.h"

void	ft_rotat_a(t_list **list_a, int a_val)
{
	while (*list_a && (*list_a)->val != a_val)
	{
		printf("ra\n");
		ra(list_a);
	}
}

void	ft_rotat_b(t_list **list_b, int b_val)
{
	while (*list_b && (*list_b)->val != b_val)
	{
		printf("rb\n");
		rb(list_b);
	}
}

