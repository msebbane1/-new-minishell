/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:36:09 by lbally            #+#    #+#             */
/*   Updated: 2022/07/22 12:36:10 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		s1len;
	int		s2len;
	int		i;
	int		j;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	s1len = ft_strlen((char *)s1);
	s2len = ft_strlen((char *)s2);
	i = -1;
	j = -1;
	if (!(str = malloc(sizeof(char) * (s1len + s2len) + 2)))
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	str[i] = ' ';
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = '\0';
	return (str);
}
