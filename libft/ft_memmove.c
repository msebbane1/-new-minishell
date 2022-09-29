/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:33:53 by lbally            #+#    #+#             */
/*   Updated: 2022/09/28 17:52:03 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*d;
	char	*s;
	char	*lasts;
	char	*lastd;

	d = (char *)dest;
	s = (char *)src;
	lasts = s + (len - 1);
	lastd = d + (len - 1);
	if ((s == NULL) && (d == NULL))
		return (0);
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
		while (len--)
			*lastd-- = *lasts--;
	return (dest);
}
