#include "push_swap.h"

char	*get_next_line(void)
{
	char	line[5];
	char	c;
	int		readreturn;
	int		i;

	line = NULL;
	i = 0;
	while (1)
	{
		readreturn = read(0, &c, 1);
		if (readreturn == -1)
			return (NULL);
		line[i++] = c;
		if (readreturn == 0 || c == '\n' || i == 4)
			break;
	}
	line[i] = '\0';
	return (line);
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

void	ft_take_op(t_list **list_a, t_list **list_b, int asize)
{
    char		*str;

	str = get_next_line();
	while (str)
	{
		get_operate(str);
		str = get_next_line();
	}
}