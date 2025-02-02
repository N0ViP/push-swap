/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:02:31 by yjaafar           #+#    #+#             */
/*   Updated: 2025/02/02 06:33:56 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>
//# include "ft_printf.h"

# define LIST_MAX 500
# define MAX_INT 2147483647
typedef struct	s_list
{
	int				val;
	int				idx;
	struct s_list*	next;
}	t_list;

int	ft_isdigit(int c);
int	ft_isspace(int c);
void    ft_lstadd_back(t_list **lst, t_list *new);

#endif
