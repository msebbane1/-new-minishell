/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:07:43 by lbally            #+#    #+#             */
/*   Updated: 2022/09/28 20:13:23 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**export5(char **tab, t_exp *atc)
{
	t_exp	*list;
	int		i;

	i = 0;
	list = atc;
	while (list->next != NULL)
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
