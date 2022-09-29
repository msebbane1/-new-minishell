/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:37:20 by lbally            #+#    #+#             */
/*   Updated: 2022/09/28 17:57:18 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char	*first, const char	*second, size_t length)
{
	unsigned int	i;
	unsigned char	*f;
	unsigned char	*s;

	f = (unsigned char *) first;
	s = (unsigned char *) second;
	i = 0;
	if (length == 0)
		return (0);
	if (!first || !second)
		return (0);
	while (f[i] == s[i] && f[i] != '\0' && s[i] != '\0'
		&& i < length - 1)
		i++;
	return (f[i] - s[i]);
}
