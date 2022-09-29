/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:10:36 by lbally            #+#    #+#             */
/*   Updated: 2022/09/29 06:30:30 by lbally           ###   ########.fr       */
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
	new->name = strdup(prt[0]);
	new->mean = strdup(prt[1]);
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
	new->mean = ft_concatenate(prt[1], "=");
	new->mean = ft_concatenate(new->mean, prt[2]);
	while (prt[i])
	{
		new->mean = ft_concatenate(new->mean, "=");
		new->mean = ft_concatenate(new->mean, prt[i]);
		i++;
	}
	new->next = NULL;
	return (tmp);
}

t_exp	*add4_3(t_exp *tmp, char **prt)
{
	int		i;
	t_exp	*new;

	i = 3;
	new = malloc(sizeof(*tmp));
	while (ft_strcmp(tmp->name, prt[0]))
		tmp = tmp->next;
	tmp->mean = ft_concatenate(prt[1], "=");
	tmp->mean = ft_concatenate(tmp->mean, prt[2]);
	while (prt[i])
	{
		tmp->mean = ft_concatenate(tmp->mean, "=");
		tmp->mean = ft_concatenate(tmp->mean, prt[i]);
		i++;
	}
	return (tmp);
}
