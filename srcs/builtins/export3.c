/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:07:43 by lbally            #+#    #+#             */
/*   Updated: 2022/10/10 14:07:13 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**export5(char **tab, t_exp *atc)
{
	t_exp	*list;
	int		i;

	i = 0;
	list = atc;
	while (list)
	{
		if (list->mean)
		{
			list->name = ft_concatenate(list->name, "=");
			tab[i] = ft_concatenate(list->name, list->mean);
		}
		else
			tab[i] = list->name;
		i++;
		list = list->next;
	}
	tab[i] = NULL;
	return (tab);
}

int	check3(int j, int t)
{
	if (t != 0)
		return (4);
	if (j == 0)
		return (2);
	if (j > 1)
		return (3);
	return (1);
}

int	check2(char *str, int i, int j)
{
	int		t;
	int		r;

	t = 0;
	r = 0;
	while (str[i])
	{
		if (!ft_isalpha(str[0]))
			return (0);
		if (str[i] == '+' && j == 0)
			r++;
		if (str[i] == '-' || r > 1)
			return (0);
		if (str[i] == '=' && str[i - 1] == '+' && j == 0)
			t++;
		if (str[i] == '=')
		{
			j++;
			while (str[i] == '=')
				i++;
		}
		i++;
	}
	return (check3(j, t));
}
