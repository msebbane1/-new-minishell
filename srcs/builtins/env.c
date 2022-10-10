/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:23:38 by lbally            #+#    #+#             */
/*   Updated: 2022/10/10 13:52:13 by lbally           ###   ########.fr       */
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
		free(tab);
	}
	if (envp[0] == NULL)
	{
		new = ft_lstnew(ft_strdup(getcwd(NULL, 0)), "PWD=");
		ft_lstadd_back(alst, new);
	}
}

t_list	*add2_2(t_list *tmp, char **prt)
{
	t_list	*new;

	new = malloc(sizeof(*tmp));
	while (tmp->next != NULL)
			tmp = tmp->next;
	tmp->next = new;
	new->key = prt[0];
	new->content = prt[1];
	new->next = NULL;
	return (tmp);
}

t_list	*add2(t_list *alst, char *str)
{
	t_list	*tmp;
	char	**prt;
	t_list	*baba;
	int		g;

	g = 0;
	baba = alst;
	tmp = alst;
	prt = (char **)malloc(sizeof(char *) * 3);
	prt[0] = ft_prt(str);
	prt[1] = ft_prt2(str);
	prt[2] = NULL;
	while (baba)
	{
		if (!ft_strcmp(baba->key, prt[0]))
			g++;
		baba = baba->next;
	}
	add2_1(tmp, prt, g);
	return (alst);
}

t_list	*add5_2(t_list *tmp, char **prt)
{
	int		i;
	t_list	*new;

	i = 3;
	new = malloc(sizeof(*tmp));
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->key = prt[0];
	new->content = prt[1];
	new->next = NULL;
	return (tmp);
}

t_list	*add5_3(t_list *tmp, char **prt)
{
	int		i;

	i = 3;
	while (ft_strcmp(tmp->key, prt[0]))
		tmp = tmp->next;
	tmp->content = prt[1];
	return (tmp);
}
