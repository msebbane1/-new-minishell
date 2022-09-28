/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:26:14 by lbally            #+#    #+#             */
/*   Updated: 2022/09/28 21:48:55 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*dollar2(char *str, int j)
{
	char	*doll;
	int		i;

	i = 0;
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

char	*dollar3(char *str, int j, int h)
{
	char	*doll;
	int		i;

	i = 0;
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

char	*dollar4(char *str, int j, int h)
{
	char	*doll;
	int		i;

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
	doll[h] = '\0';
	return (doll);
}

char	*dollar1(char *str, int h, int i, int l)
{
	int	j;

	j = i;
	if (l != 0)
		return (dollar3(str, j, h));
	else
		return (dollar4(str, j, h));
	return (NULL);
}

char	*dollar(char *str, int c)
{
	int		i;
	int		j;
	int		t;
	int		h;
	int		l;

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
	if (t != 0 && c != 0)
		return (dollar2(str, j));
	return (dollar1(str, h, i, l));
}
