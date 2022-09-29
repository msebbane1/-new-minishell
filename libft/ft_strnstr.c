/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:39:47 by lbally            #+#    #+#             */
/*   Updated: 2022/09/28 17:57:24 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s2[i] == 0)
		return ((char *)s1);
	while (s1[i] && i < len)
	{
		while (s1[i + j] == s2[j] && ((i + j) < len))
		{
			j++;
			if (s2[j] == '\0')
				return ((char *)&s1[i]);
		}
		i++;
		j = 0;
	}
	return (0);
}
