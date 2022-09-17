/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:40:16 by lbally            #+#    #+#             */
/*   Updated: 2022/07/26 17:04:07 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:40:16 by lbally            #+#    #+#             */
/*   Updated: 2022/07/22 12:40:16 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isin(char c, const char *set)
{
	int		i;

	i = -1;
	while (set[++i])
		if (c == set[i])
			return (1);
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		k;
	int		j;
	int		size;

	size = 0;
	j = ft_strlen((char *)s1) - 1;
	k = 0;
	i = 0;
	while (ft_isin(s1[i], set) == 1)
		i++;
	while (ft_isin(s1[j], set) == 1)
		j--;
	size = i > j ? 2 : (j - i);
	if (!(str = malloc(sizeof(char) * (size + 2))))
		return (NULL);
	while (i <= j)
		str[k++] = s1[i++];
	str[k] = '\0';
	return (str);
}
