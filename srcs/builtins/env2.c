/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:50:36 by lbally            #+#    #+#             */
/*   Updated: 2022/09/28 18:56:57 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_list	*add5(t_list *alst, char *str)
{
	t_list	*tmp;
	char	**prt;
	t_list	*baba;
	int		g;

	g = 0;
	baba = alst;
	tmp = alst;
	prt = ft_split(str, '=');
	while (baba)
	{
		if (!ft_strcmp(baba->key, prt[0]))
			g++;
		baba = baba->next;
	}
	if (g == 0)
		tmp = add5_2(tmp, prt);
	else
		tmp = add5_3(tmp, prt);
	return (alst);
}
