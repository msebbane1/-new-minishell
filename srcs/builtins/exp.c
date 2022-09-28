/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:29:52 by lbally            #+#    #+#             */
/*   Updated: 2022/09/27 20:43:55by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_exp	*explast(t_exp *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_exp	*expnew(void *content, char *key)
{
	t_exp	*element;

	element = malloc(sizeof(*element));
	if (!element)
		return (NULL);
	element->mean = content;
	element->name = key;
	element->next = NULL;
	return (element);
}

void	ft_exp(t_exp **atc, t_exp *new)
{
	t_exp	*tmp;

	if (!*atc)
		*atc = new;
	else
	{
		tmp = explast(*atc);
		tmp->next = new;
	}
}

void	insert_exp(char **envp, t_exp **atc)
{
	t_exp	*new;
	char	**tab;
	int		i;

	i = -1;
	while (envp[++i])
	{
		tab = ft_split(envp[i], '=');
		new = expnew(tab[1], tab[0]);
		ft_exp(atc, new);
		free(tab);
	}
	if (envp[0] == NULL)
	{
		printf("insert_env envp[o]\n");
		new = expnew(ft_strdup(getcwd(NULL, 0)), "PWD=");
		ft_exp(atc, new);
	}
}

t_exp	*add(t_exp *atc, char *str)
{
	t_exp	*tmp;
	t_exp	*new;
	t_exp	*baba;
	char	**prt;
	int		g;

	new = malloc(sizeof(*tmp));
	g = 0;
	tmp = atc;
	baba = atc;
	prt = NULL;
	prt = (char **)malloc(sizeof(char *) * 3);
	prt = ft_split(str, '=');
	while (baba)
	{
		if (!ft_strcmp(baba->name, prt[0]))
			g++;
		baba = baba->next;
	}
	if (g == 0)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->name = prt[0];
		new->mean = prt[1];
		new->next = NULL;
	}
	else
	{
		while (ft_strcmp(tmp->name, prt[0]) != 0)
			tmp = tmp->next;
		tmp->mean = prt[1];
	}
	return (atc);
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

t_exp	*add4(t_exp *atc, char *str)
{
	t_exp	*tmp;
	t_exp	*new;
	char	**prt;
	t_exp	*baba;
	int		g;
	int		i;

	i = 3;
	g = 0;
	baba = atc;
	new = malloc(sizeof(*tmp));
	tmp = atc;
	prt = ft_split(str, '=');
	while (baba)
	{
		if (!ft_strcmp(baba->name, prt[0]))
			g++;
		baba = baba->next;
	}
	if (g == 0)
	{
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
	}
	else
	{
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
	}
	return (atc);
}
