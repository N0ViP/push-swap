/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:43:54 by yjaafar           #+#    #+#             */
/*   Updated: 2025/01/17 16:44:07 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_fill_res(char **res, char *str)
{
	int	i;
	int	j;

	j = 0;
	while (*str)
	{
		i = 0;
		while (*s && (*s == ' ' || *s >= 9 && *s <= 13))
			s++;
		while (*s && !(*s == ' ' || *s >= 9 && *s <= 13))
		{
			s++;
			i++;
		}
		if (*s || (!*s && !(*(s - 1) == ' ' || *(s - 1) >= 9 && *(s - 1) <= 13)))
		{
			res[j] = (char *) malloc(i + 1);
			if (!res[j])
				return (ft_free(res, j - 1), NULL);
		}
		ft_memcopy(res[j++], str, i);
	}
	res[j] = NULL;
	return (res);
}

char	ft_split(char *str)
{
	char	**res;
	int		wc;

	wc = ft_count_words(str);
	res = (char **) malloc(sizeof(char *) * (wc + 1));
	if (!res)
		return (NULL);
	ft_fill_res(res, str);
}