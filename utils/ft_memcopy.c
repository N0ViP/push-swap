/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcopy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:59:48 by yjaafar           #+#    #+#             */
/*   Updated: 2025/01/17 18:00:05 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void	*ft_memcopy(void *dest, void *src, size_t l)
{
	register void  *d = dest;
	register void  *s = src;
	register size_t len = l;

	if (!dest || !src)
		return NULL;
	while (len && ((size_t) d % 8 == 0))
	{
		*((char *) d++) = *((char *) s++);
		len--;
	}
	while (len >= sizeof(size_t))
	{
		*((size_t *) d) = *((size_t *) s);
		d += sizeof(size_t);
		s += sizeof(size_t);
		len -= sizeof(size_t);
	}
	while (len)
	{
		*((char *) d++) = *((char *) s++);
		len--;
	}
	return (dest);
}

int main()
{
	char *src = malloc(200000001);
	char *dest = malloc(200000001);
	for (int i = 0; i < 50; i++)
	{
		dest = ft_memcopy(dest, src, 200000000);
	}
}