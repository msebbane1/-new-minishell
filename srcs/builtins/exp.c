/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:29:52 by lbally            #+#    #+#             */
/*   Updated: 2022/10/09 21:02:11 by lbally           ###   ########.fr       */
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
		new = expnew(ft_strdup(getcwd(NULL, 0)), "PWD=");
		ft_exp(atc, new);
	}
}

t_exp	*add(t_exp *atc, char *str)
{
	t_exp	*tmp;
	t_exp	*baba;
	char	**prt;
	int		g;

	g = 0;
	tmp = atc;
	baba = atc;
	prt = NULL;
	prt = (char **)malloc(sizeof(char *) * 3);
	prt[0] = ft_prt(str);
	prt[1] = ft_prt2(str);
	prt[2] = NULL;
	while (baba)
	{
		if (!ft_strcmp(baba->name, prt[0]))
			g++;
		baba = baba->next;
	}
	tmp = add_2(tmp, prt, g);
	return (atc);
}
