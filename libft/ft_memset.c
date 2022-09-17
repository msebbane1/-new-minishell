/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:34:06 by lbally            #+#    #+#             */
/*   Updated: 2022/07/22 12:34:07 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int val, size_t len)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)dest;
	i = -1;
	while (++i < len)
		ptr[i] = val;
	return (dest);
}
