#include "push_swap.h"

void	checker_r(t_list **list)
{
	t_list	*tmp;
	t_list	*ptr;

	if (!list || !*list || !(*list)->next)
		return ;
	tmp = *list;
	*list = (*list)->next;
	ptr = *list;
	tmp->next = NULL;
	while (ptr->next)
	{
		ptr = ptr->next;
	}
	ptr->next = tmp;
}

void	checker_rr(t_list **list_a, t_list **list_b)
{
	checker_r(list_a);
	checker_r(list_b);
}

void	checker_rrab(t_list **list)
{
	t_list	*tmp;
	t_list	*ptr;

	if (!list || !*list || !(*list)->next)
		return ;
	ptr = *list;
	while (ptr->next->next)
	{
		ptr = ptr->next;
	}
	tmp = *list;
	*list = ptr->next;
	ptr->next = NULL;
	(*list)->next = tmp;
}

void	checker_rrr(t_list **list_a, t_list **list_b)
{
	checker_rrab(list_a);
	checker_rrab(list_b);
}

void	checker_p(t_list **list_a, t_list **list_b)
{
	t_list	*tmp;

	if (!list_a || !list_b || !(*list_b))
		return ;
	tmp = *list_a;
	*list_a = *list_b;
	*list_b = (*list_b)->next;
	(*list_a)->next = tmp;
}

void	checker_s(t_list **list)
{
	t_list	*tmp;

	if (!list || !*list || !(*list)->next)
		return ;
	tmp = *list;
	*list = (*list)->next;
	tmp->next = (*list)->next;
	(*list)->next = tmp;
}

void	checker_ss(t_list **list_a, t_list **list_b)
{
	checker_s(list_a);
	checker_s(list_b);
}
