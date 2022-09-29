/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:47:51 by lbally            #+#    #+#             */
/*   Updated: 2022/09/28 18:48:16 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_exp	*add4(t_exp *atc, char *str)
{
	t_exp	*tmp;
	char	**prt;
	t_exp	*baba;
	int		g;

	g = 0;
	baba = atc;
	tmp = atc;
	prt = ft_split(str, '=');
	while (baba)
	{
		if (!ft_strcmp(baba->name, prt[0]))
			g++;
		baba = baba->next;
	}
	if (g == 0)
		tmp = add4_2(tmp, prt);
	else
		tmp = add4_3(tmp, prt);
	return (atc);
}
