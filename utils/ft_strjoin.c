/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 06:01:22 by yjaafar           #+#    #+#             */
/*   Updated: 2025/01/18 06:43:41 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t.h"

int	ft_strlen(char *str)
{
	register int	i;
	register char	*s;

	i = 0;
	s = str;
	while (s[i])
		i++;
	return (i);
}

int	ft_strcnt(char **str)
{
	register int	strcnt;
	register char	**s;

	strcnt = 0;
	s = str;
	while (s[strcnt])
		strcnt++;
	return (strcnt);
}

int	ft_total(int *arr_lens, char **str, int strcnt)
{
	int				tmp;
	register int	total;
	register int	*arr;
	register char	**s;

	tmp = 0;
	total = 0;
	arr = arr_lens;
	s = str;
	while (tmp < strcnt)
	{
		arr[tmp] = ft_strlen(s[tmp]);
		total += arr[tmp++];
		total += (tmp < strcnt);
	}
	return (total);
}

void	ft_fill_res(char *res, char **str, int *arr_lens, int strcnt)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = res;
	while (i < strcnt)
	{
		tmp = ft_memcpy(tmp, str[i], arr_lens[i]);
		tmp += arr_lens[i++];
		if (i < strcnt)
		{
			*tmp++ = ' ';
		}
	}
	*tmp = '\0';
}

char	*ft_strjoin(char **str)
{
	char	*res;
	int		total;
	int		*arr_lens;
	int		strcnt;

	strcnt = ft_strcnt(str);
	arr_lens = (int *) malloc(sizeof(int) * strcnt);
	if (!arr_lens)
		return (NULL);
	total = ft_total(arr_lens, str, strcnt);
	res = (char *) malloc(total + 1);
	if (!res)
		return (free(arr_lens), NULL);
	ft_fill_res(res, str, arr_lens, strcnt);
	return (free(arr_lens), res);
}
