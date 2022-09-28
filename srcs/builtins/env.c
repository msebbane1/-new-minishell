/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:23:38 by lbally            #+#    #+#             */
/*   Updated: 2022/09/28 00:51:14 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	insert_env(char **envp, t_list **alst)
{
	t_list	*new;
	char	**tab;
	int		i;

	i = -1;
	while (envp[++i])
	{
		tab = ft_split(envp[i], '=');
		new = ft_lstnew(tab[1], tab[0]);
		ft_lstadd_back(alst, new);
		free(tab); // faire un free_tab(tab)
	}
	if (envp[0] == NULL)
	{
		new = ft_lstnew(ft_strdup(getcwd(NULL, 0)), "PWD=");
		ft_lstadd_back(alst, new);
	}
}

t_list	*add2(t_list *alst, char *str)
{
	t_list	*tmp;
	t_list	*new;
	char	**prt;
	t_list	*baba;
	int		g;

	g = 0;
	baba = alst;
	new = malloc(sizeof(*tmp));
	tmp = alst;
	prt = (char **)malloc(sizeof(char *) * 3);
	prt = ft_split(str, '=');
	while (baba)
	{
		if (!ft_strcmp(baba->key, prt[0]))
			g++;
		baba = baba->next;
	}
	if (g == 0)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->key = prt[0];
		new->content = prt[1];
		new->next = NULL;
	}
	else
	{
		while (ft_strcmp(tmp->key, prt[0]) != 0)
			tmp = tmp->next;
		tmp->content = prt[1];
	}
	return (alst);
}

t_list	*add5(t_list *alst, char *str)
{
	t_list	*tmp;
	t_list	*new;
	char	**prt;
	t_list	*baba;
	int		g;
	int		i;

	i = 3;
	g = 0;
	baba = alst;
	new = malloc(sizeof(*tmp));
	tmp = alst;
	prt = ft_split(str, '=');
	while (baba)
	{
		if (!ft_strcmp(baba->key, prt[0]))
			g++;
		baba = baba->next;
	}
	if (g == 0)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->key = prt[0];
		new->content = ft_concatenate(prt[1], "=");
		new->content = ft_concatenate(new->content, prt[2]);
		while (prt[i])
		{
			new->content = ft_concatenate(new->content, "=");
			new->content = ft_concatenate(new->content, prt[i]);
			i++;
		}
		new->next = NULL;
	}
	else
	{
		while (ft_strcmp(tmp->key, prt[0]))
			tmp = tmp->next;
		tmp->content = ft_concatenate(prt[1], "=");
		tmp->content = ft_concatenate(tmp->content, prt[2]);
		while (prt[i])
		{
			tmp->content = ft_concatenate(tmp->content, "=");
			tmp->content = ft_concatenate(tmp->content, prt[i]);
			i++;
		}
	}
	return (alst);
}
