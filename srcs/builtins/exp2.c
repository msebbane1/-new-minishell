/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:10:36 by lbally            #+#    #+#             */
/*   Updated: 2022/10/09 20:55:55 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_exp	*add_2(t_exp *tmp, char **prt, int g)
{
	if (g == 0)
		tmp = add_3(tmp, prt);
	else
	{
		while (ft_strcmp(tmp->name, prt[0]) != 0)
			tmp = tmp->next;
		tmp->mean = prt[1];
	}
	return (tmp);
}

t_exp	*add_3(t_exp *tmp, char **prt)
{
	t_exp	*new;

	new = malloc(sizeof(*tmp));
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->name = ft_strdup(prt[0]);
	new->mean = ft_strdup(prt[1]);
	new->next = NULL;
	return (tmp);
}

t_exp	*add3(t_exp *atc, char *str)
{
	t_exp	*tmp;
	t_exp	*new;
	t_exp	*baba;
	int		g;

	g = 0;
	baba = atc;
	new = malloc(sizeof(t_exp) * 1);
	tmp = atc;
	while (baba)
	{
		if (!ft_strcmp(baba->name, str))
			g++;
		baba = baba->next;
	}
	if (g == 0)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->name = ft_strdup(str);
		new->mean = ft_strdup("(null)");
		new->next = NULL;
	}
	return (atc);
}

t_exp	*add4_2(t_exp *tmp, char **prt)
{
	int		i;
	t_exp	*new;

	i = 3;
	new = malloc(sizeof(*tmp));
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->name = prt[0];
	new->mean = prt[1];
	new->next = NULL;
	return (tmp);
}

t_exp	*add4_3(t_exp *tmp, char **prt)
{
	int		i;

	i = 3;
	while (ft_strcmp(tmp->name, prt[0]))
		tmp = tmp->next;
	tmp->mean = prt[1];
	return (tmp);
}
