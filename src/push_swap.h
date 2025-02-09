/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:02:31 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/09 17:55:19 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>


# define STACK_MAX 2097152

typedef struct	s_list
{
	int				val;
	int				idx;
	struct s_list*	next;
}	t_list;

typedef	void(*operation)(t_list **list);

/* Operations */

void	ra(t_list **lista);
void	pb(t_list **listb, t_list **lista);
void	pa(t_list **list_a, t_list **list_b);
void	rb(t_list **listb);
void    rrb(t_list **listb);
void    rra(t_list **lista);




void ft(t_list *list);
int		ft_isdigit(int c);
int		ft_isspace(int c);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_move_to_b(t_list **list_a, t_list **list_b, int asize);
void    ft_move_to_a(t_list **list_a, t_list **list_b, int asize);
void    ft_move_to_top(t_list **list_a, int asize);

#endif
