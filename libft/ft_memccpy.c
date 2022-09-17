/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:32:53 by lbally            #+#    #+#             */
/*   Updated: 2022/07/22 12:32:54 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char *s;
	unsigned char l;
	unsigned char *d;

	d = (unsigned char *)dest;
	l = (unsigned char)c;
	s = (unsigned char *)src;
	while (n && *s != l)
	{
		*d++ = *s++;
		n--;
	}
	if (*s == l && n)
	{
		*d++ = *s++;
		return ((void *)d);
	}
	return (NULL);
}
