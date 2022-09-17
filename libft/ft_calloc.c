/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:29:23 by lbally            #+#    #+#             */
/*   Updated: 2022/09/05 23:58:51 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	str = 0;
	if (count == 0 || size == 0)
	{
		size = 1;
		count = 1;
	}
	str = malloc(count * size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, count * size);
	return (str);
}
