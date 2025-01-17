/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcopy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaafar <yjaafar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:59:48 by yjaafar           #+#    #+#             */
/*   Updated: 2025/01/17 22:12:24 by yjaafar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
