/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:23:38 by lbally            #+#    #+#             */
/*   Updated: 2022/09/18 16:23:28 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	update_env(t_list *alst, char *path)
{
	t_list	*list;
	char	*content;
	char	*new_content;

	list = alst;
	while (list)
	{
		if (!ft_strcmp(list->key, "PWD"))
		{
			content = ft_strcpy(list->content, content);
			new_content = path;
			free(list->content);
			list->content = new_content;
		}
		if (!ft_strcmp(list->key, "OLDPWD"))
			list->content = content;
		list = list->next;
	}
}

/*char	**putenv_in_tab(t_list *alst)
{
	t_list	*list;
	char	**tab;
	int		i;

	i = 0;
	list = alst;
	tab = malloc(sizeof(char *) * len_list(alst) + 1);
	while (list)
	{
		tab[i] = ft_strjoin(list->key, "=");
		tab[i] = ft_strjoin(tab[i], list->content);
		i++;
		list = list->next;
	}
	tab[i] = NULL;
	return (tab);
}*/

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
	return (alst);
}
