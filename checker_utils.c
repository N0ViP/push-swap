#include "push_swap.h"

int	get_next_line(char *str)
{
	char	c;
	int		readreturn;
	int		i;

	i = 0;
	while (1)
	{
		readreturn = read(0, &c, 1);
		if (readreturn == -1 || readreturn == 0)
			return (-1);
		str[i++] = c;
		if (c == '\n' || i == 4)
			break;
	}
	str[i] = '\0';
	return (1);
}

void	ft_error(void)
{
	int		i;
	char	c;

	i = read(0, &c, 1);
	while (i && i != -1)
	{
		i = read(0, &c, 1);
	}
	write(2, "Error\n", 6);
	exit(1);
}

void	get_operation(char *str, t_list **list_a, t_list **list_b)
{
	if (!ft_strcmp(str, "ra\n"))
		checker_r(list_a);
	if (!ft_strcmp(str, "rb\n"))
		checker_r(list_b);
	if (!ft_strcmp(str, "rr\n"))
		checker_rr(list_a, list_b);
	if (!ft_strcmp(str, "rra\n"))
		checker_rrab(list_a);
	if (!ft_strcmp(str, "rrb\n"))
		checker_rrab(list_b);
	if (!ft_strcmp(str, "rrr\n"))
		checker_rrr(list_a, list_b);
	if (!ft_strcmp(str, "pa\n"))
		checker_p(list_a, list_b);
	if (!ft_strcmp(str, "pb\n"))
		checker_p(list_b, list_a);
	if (!ft_strcmp(str, "sa\n"))
		checker_s(list_a);
	if (!ft_strcmp(str, "sb\n"))
		checker_s(list_b);
	if (!ft_strcmp(str, "ss\n"))
		checker_ss(list_a, list_b);
	ft_error();
}

void	ft_take_op(t_list **list_a, t_list **list_b)
{
    char	str[5];
	int		i;

	i = get_next_line(str);
	while (i != -1)
	{
		get_operation(str, list_a, list_b);
		i = get_next_line(str);
	}
}