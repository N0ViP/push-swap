#include "push_swap.h"

void ft(t_list *list)
{
	while (list)
	{
		printf("%d\n", list->val);
		list = list->next;
	}
}
