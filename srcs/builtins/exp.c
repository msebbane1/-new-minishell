/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:29:52 by lbally            #+#    #+#             */
/*   Updated: 2022/09/17 15:50:52 by msebbane         ###   ########.fr       */
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
}

t_exp	*add(t_exp *atc, char *str)
{
	t_exp	*tmp;
	t_exp	*new;
	char	**prt;

	new = malloc(sizeof(*tmp));
	tmp = atc;
	prt = (char **)malloc(sizeof(char *) * 3);
	prt = ft_split(str, '=');
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->name = prt[0];
	new->mean = prt[1];
	new->next = NULL;
	return (atc);
}

t_exp	*add3(t_exp *atc, char *str)
{
	t_exp	*tmp;
	t_exp	*new;

	new = malloc(sizeof(*tmp));
	tmp = atc;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->name = str;
	new->mean = "(null)";
	new->next = NULL;
	return (atc);
}

t_exp	*add4(t_exp *atc, char *str)
{
	t_exp	*tmp;
	t_exp	*new;
	char	**prt;
	int		i;

	i = 3;
	new = malloc(sizeof(*tmp));
	tmp = atc;
	prt = ft_split(str, '=');
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
	return (atc);
}