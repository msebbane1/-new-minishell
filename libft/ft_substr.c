/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:40:32 by lbally            #+#    #+#             */
/*   Updated: 2022/09/28 21:51:16 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	int				pop;
	char			*res;

	pop = 0;
	if (!s)
		return (NULL);
	if ((start >= ft_strlen(s)) || (len == 0))
		return (ft_calloc(1, sizeof(char)));
	len = len - start;
	i = 0;
	while (s[i])
	{
		if (s[i] == '"')
			pop++;
		i++;
	}
	i = 0;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (pop % 2 == 0 && pop != 0)
		res = (char *)malloc(sizeof(char) * (len + 1));
	else if (pop % 2 == 1 && pop != 0)
		return (NULL);
	else if (!res)
		return (NULL);
	while (i < len)
	{
		if (s[start] == '"')
			while (s[start] == '"')
				start++;
		res[i++] = s[start++];
	}
	res[i] = '\0';
	return (res);
}
