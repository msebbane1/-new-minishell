/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:26:14 by lbally            #+#    #+#             */
/*   Updated: 2022/09/15 15:59:36 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*dollar(char *str)
{
	int		i;
	int		j;
	int		t;
	int		h;
	int		l;
	char	*doll;

	i = 0;
	t = 0;
	l = 0;
	while (str[i])
	{
		if (!ft_cmpchar(str[i], '\''))
			t++;
		if (!ft_cmpchar(str[i], '\"'))
			l++;
		if (!ft_cmpchar(str[i], '$'))
			h = i;
		i++;
	}
	j = i;
	i = 0;
	if (t != 0)
	{
		doll = malloc(sizeof(char) * (j - 2));
		j = 0;
		while (str[i] != '\0')
		{
			if (!ft_cmpchar(str[i], '\''))
				i++;
			doll[j++] = str[i++];
		}
		return (doll);
	}
	else if (l != 0)
	{
		doll = malloc(sizeof(char) * (j - 4));
		j = 0;
		while (str[i] != '\0')
		{
			if (!ft_cmpchar(str[i], '\"'))
				i++;
			if (i == h)
				i = i + 2;
			doll[j++] = str[i++];
		}
		return (doll);
	}
	else
	{
		doll = malloc(sizeof(char) * (j - 2));
		i = 0;
		h = 0;
		while (str[i])
		{
			if (!ft_cmpchar(str[i], '$'))
				i = i + 2;
			doll[h] = str[i];
			i++;
			h++;
		}
		return (doll);
	}
	return (NULL);
}
