/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:11:16 by msebbane          #+#    #+#             */
/*   Updated: 2022/09/29 18:16:45 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_set(char c, char const *set)
{
	int	i;
	int	size_set;

	i = 0;
	size_set = ft_strlen(set);
	while (i < size_set)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*finalstr(char *s1, int i, int j)
{
	int		len;
	char	*str;

	if (!s1)
		return (0);
	len = (ft_strlen(s1)) - (i + j);
	if (len < 0)
		str = (char *) malloc(sizeof(char));
	else
		str = (char *) malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (j < len)
	{
		str[j] = s1[i + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

/**
 * Alloue (avec malloc) et retourne une copie de
 * la chaine ’s1’, sans les caractères spécifiés
 * dans ’set’ au début et à la fin de la chaine de
 * caractères.
**/
char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = ft_strlen(s1);
	if (!s1)
		return (0);
	while (s1[i] && ft_is_set(s1[i], set))
		i++;
	while (ft_is_set(s1[size - 1], set) && size >= 0)
	{
		size--;
		j++;
	}
	return (finalstr((char *)s1, i, j));
}
