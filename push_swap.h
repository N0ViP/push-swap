/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:02:31 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/13 05:39:07 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

# define STACK_MAX 2097152

typedef struct s_list
{
	int				val;
	int				idx;
	struct s_list	*next;
}	t_list;

/*amove and bmove represnt the operation*/
/*if (a)(b)move == 0 then rrx*/
/*if (a)(b)move == 1 then rx*/

typedef struct s_stock
{
	int	asize;
	int	bsize;
	int	target;
	int	num;
	int	tmp_target;
	int	amove;
	int	tmp_amove;
	int	tmp_bmove;
	int	bmove;
}	t_stock;

typedef void(*t_operation)(t_list **list);

/* Operations */
void	ra(t_list **lista);
void	rb(t_list **listb);
void	sa(t_list **lista);
void	rrb(t_list **listb);
void	rra(t_list **lista);
void	rr(t_list **lista, t_list **listb);
void	pb(t_list **listb, t_list **lista);
void	rrr(t_list **lista, t_list **listb);
void	pa(t_list **list_a, t_list **list_b);


/* checker functions */
void	checker_r(t_list **list);
void	checker_rr(t_list **list_a, t_list **list_b);
void	checker_rrab(t_list **list);
void	checker_rrr(t_list **list_a, t_list **list_b);
void	checker_p(t_list **list_a, t_list **list_b);
void	checker_s(t_list **list);
void	checker_ss(t_list **list_a, t_list **list_b);
void	ft_take_op(t_list **list_a, t_list **list_b);
int		ft_strcmp(const char *s1, const char *s2);

/* utils */
int		ft_isspace(int c);
int		ft_isdigit(int c);
int		ft_atoi(char **av);
int		ft_list_len(t_list *list);
void	ft_sort_three(t_list **a);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_move_to_top(t_list **list_a, int asize);
void	ft_move_to_a(t_list **list_a, t_list **list_b);
void	ft_move(t_list **list_a, t_list **list_b, t_stock *stock);
void	ft_move_to_b(t_list **list_a, t_list **list_b, int asize);

#endif
