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
	exit(1);
}

void	get_operation(char *str)
{
	if (!ft_strcmp(str, "ra\n"))
		return (ra);
	if (!ft_strcmp(str, "rb\n"))
		return (rb);
	if (!ft_strcmp(str, "rr\n"))
		return (rr);
	if (!ft_strcmp(str, "rra\n"))
		return (rra);
	if (!ft_strcmp(str, "rrb\n"))
		return (rrb);
	if (!ft_strcmp(str, "rrr\n"))
		return (rrr);
	if (!ft_strcmp(str, "pa\n"))
		return (pa);
	if (!ft_strcmp(str, "pb\n"))
		return (pb);
	if (!ft_strcmp(str, "sa\n"))
		return (sa);
	if (!ft_strcmp(str, "sb\n"))
		return (sb);
	if (!ft_strcmp(str, "ss\n"))
		return (ss);
	ft_error();
}

void	ft_check_list(t_list **list_a, t_list **list_b, int asize)
{
    char		*str;
	operation	op;

	str = get_next_line();
	while (str)
	{
		op = get_operation(str);
		`
		str = get_next_line();
	}
}