/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:43:54 by yjaafar           #+#    #+#             */
/*   Updated: 2025/01/18 01:18:09 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free(char **res, int j)
{
	while (j >= 0)
	{
		free(res[j--]);
	}
	free(res);
}

static char	**ft_fill_res(char **res, char *s)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (s[k])
	{
		i = 0;
		while (s[k] && (s[k] == ' ' || s[k] >= 9 && s[k] <= 13))
			k++;
		while (s[k + i] && !(s[k + i] == ' ' || s[k + i] >= 9 && s[k + i] <= 13))
		{
			i++;
		}
		if (i)
		{
			res[j] = (char *) malloc(i + 1);
			if (!res[j])
				return (ft_free(res, j - 1), NULL);
			ft_memcpy(res[j], s + k, i);
			res[j++][i] = '\0';
		}
		k += i;
	}
	res[j] = NULL;
	return (res);
}

char	**ft_split(char *str)
{
	char	**res;
	int		wc;

	wc = ft_count_words(str);
	res = (char **) malloc(sizeof(char *) * (wc + 1));
	if (!res)
		return (NULL);
	res = ft_fill_res(res, str);
	return(res);
}

int main()
{
	char *str = "a`    hello		 world  good		well done 		 a";
	char **res = ft_split(str);
	int k = 0;
	while (res[k])
	{
		printf("%s\n", res[k]);
		k++;
	}
}
