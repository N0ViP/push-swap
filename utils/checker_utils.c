/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 05:59:30 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/17 05:06:39 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_next_line(char *str)
{
	char	c;
	int		readreturn;
	int		i;

	i = 0;
	while (i < 4)
	{
		readreturn = read(0, &c, 1);
		if (readreturn <= 0)
			return (-1);
		str[i++] = c;
		if (c == '\n')
			break ;
	}
	str[i] = '\0';
	return (1);
}

void	ft_error(char *str)
{
	char	c;
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			write(2, "Error\n", 6);
			exit(255);
		}
		i++;
	}
	while (read(0, &c, 1) > 0 && c != '\n')
		;
	write(2, "Error\n", 6);
	exit(255);
}

void	get_operation(char *str, t_list **list_a, t_list **list_b)
{
	if (!ft_strcmp(str, "ra\n"))
		checker_r(list_a);
	else if (!ft_strcmp(str, "rb\n"))
		checker_r(list_b);
	else if (!ft_strcmp(str, "rr\n"))
		checker_rr(list_a, list_b);
	else if (!ft_strcmp(str, "rra\n"))
		checker_rrab(list_a);
	else if (!ft_strcmp(str, "rrb\n"))
		checker_rrab(list_b);
	else if (!ft_strcmp(str, "rrr\n"))
		checker_rrr(list_a, list_b);
	else if (!ft_strcmp(str, "pa\n"))
		checker_p(list_a, list_b);
	else if (!ft_strcmp(str, "pb\n"))
		checker_p(list_b, list_a);
	else if (!ft_strcmp(str, "sa\n"))
		checker_s(list_a);
	else if (!ft_strcmp(str, "sb\n"))
		checker_s(list_b);
	else if (!ft_strcmp(str, "ss\n"))
		checker_ss(list_a, list_b);
	else
		ft_error(str);
}

int	ft_check_list(t_list *list_a, int asize)
{
	t_list	*ptr;
	int		i;

	i = 0;
	while (list_a)
	{
		ptr = list_a->next;
		while (ptr)
		{
			if (ptr->val < list_a->val)
			{
				return (1);
			}
			ptr = ptr->next;
		}
		list_a = list_a->next;
		i++;
	}
	if (i != asize)
		return (1);
	return (0);
}

void	ft_take_op(t_list **list_a, t_list **list_b)
{
	char	str[5];
	int		i;

	i = get_next_line(str);
	while (i == 1)
	{
		get_operation(str, list_a, list_b);
		i = get_next_line(str);
	}
}
