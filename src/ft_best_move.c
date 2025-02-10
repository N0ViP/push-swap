#include "push_swap.h"

typedef	struct s_stock
{
	int	target;
	int	num;
}	t_stock;

int	if_rotat_a(int val, int *a_val, t_list *list_a)
{
	int	n;
	int	a;
	t_list	*tmp;

	n = INT_MAX;
	a = 0;
	tmp = list_a;
	while (list_a)
	{
		if (val < list_a->val && list_a->val < n)
		{
			n = list_a->val;
		}
		list_a = list_a->next;
	}
	*a_val = n;
	while (tmp && tmp->val != n)
	{
		a++;
		tmp = tmp->next;
	}
	return (a);
}

int	move_b_to_top(int val, t_list *list_b, t_list *list_a, t_stock *tmp)
{
	int n = 0;

	while (list_b && list_b->val != val)
	{
		n++;
		list_b = list_b->next;
	}
	tmp->num = val;
	n += if_rotat_a(val, &(tmp->target), list_a);
	return (n);
}

void	ft_move_target_and_num(t_list **list_a, t_list **list_b, t_stock *res)
{
	while (*list_a && (*list_a)->val != res->target)
	{
		printf("ra\n");
		ra(list_a);
	}
	while (*list_b && (*list_b)->val != res->num)
	{
		printf("rb\n");
		rb(list_b);
	}
}

void	ft_best_move(t_list **list_a, t_list **list_b)
{
	t_list *tmp = *list_b;
	t_stock mp;
	t_stock res;
	int moves;
	int 	best = INT_MAX;
	while (tmp)
	{
		moves = move_b_to_top(tmp->val, *list_b, *list_a, &mp);
		if (moves <= best)
		{
			best = moves;
			res = (t_stock) {mp.target, mp.num};
		}
		tmp = tmp->next;
	}

	ft_move_target_and_num(list_a, list_b, &res);
}
