#include "push_swap.h"

int	if_rotat_a(int val, int *a_val, t_list *list_a)
{
	int	n;
	int	a;

	n = INT_MAX;
	a = 0;
	while (list_a)
	{
		if (val < list_a->val && list_a->val < n)
		{
			n = list_a->val;
		}
		list_a = list_a->next;
	}
	*a_val = n;
	while (list_a && list_a->val != n)
	{
		a++;
		list_a = list_a->next;
	}
	return (a);
}

int	if_rotat_b(int val, int *b_val, t_list *list_b)
{
	int	n;
	int	b;

	n = INT_MIN;
	b = 0;
	while (list_b)
	{
		if (val > list_b->val && list_b->val > n)
		{
			n = list_b->val;
		}
		list_b = list_b->next;
	}

	*b_val = n;
	while (list_b && list_b->val != n)
	{
		b++;
		list_b = list_b->next;
	}
	return (b);
}
