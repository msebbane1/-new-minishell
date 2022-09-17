/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:37:00 by lbally            #+#    #+#             */
/*   Updated: 2022/07/22 12:37:02 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = -1;
	if (!(str = malloc(sizeof(char) * ft_strlen((char *)s) + 1)))
		return (NULL);
	while (s[++i])
		str[i] = f(i, s[i]);
	str[i] = '\0';
	return (str);
}
