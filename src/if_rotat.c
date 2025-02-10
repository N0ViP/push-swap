#include "push_swap.h"

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

int	if_rotat_b(int val, int *b_val, t_list *list_b)
{
	int	n;
	int	b;
	t_list	*tmp;

	n = INT_MIN;
	b = 0;
	tmp = list_b;
	while (list_b)
	{
		if (list_b->val < val && list_b->val > n)
		{
			n = list_b->val;
		}
		list_b = list_b->next;
	}
	*b_val = n;
	while (tmp && tmp->val != n)
	{
		b++;
		tmp = tmp->next;
	}
	return (b);
}
