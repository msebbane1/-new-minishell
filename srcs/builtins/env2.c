/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:50:36 by lbally            #+#    #+#             */
/*   Updated: 2022/10/10 13:38:13 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	add2_1(t_list *tmp, char **prt, int g)
{
	if (g == 0)
		tmp = add2_2(tmp, prt);
	else
	{
		while (ft_strcmp(tmp->key, prt[0]) != 0)
			tmp = tmp->next;
		tmp->content = prt[1];
	}
}

t_list	*add5(t_list *alst, char *str)
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
	if (g == 0)
		tmp = add5_2(tmp, prt);
	else
		tmp = add5_3(tmp, prt);
	return (alst);
}

t_list	*add7_1(t_list *tmp, char *prt, char *prt2, int g)
{
	t_list	*new;

	new = malloc(sizeof(*tmp));
	if (g == 0)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->key = ft_strdup(prt);
		new->content = ft_strdup(prt2);
		new->next = NULL;
	}
	else
	{
		while (ft_strcmp(tmp->key, prt))
			tmp = tmp->next;
		tmp->content = ft_strdup(ft_strjoin_no_spc(tmp->content, prt2));
	}
	return (tmp);
}

t_list	*add7(t_list *alst, char *str)
{
	t_list	*tmp;
	char	*prt;
	char	*prt2;
	int		g;

	g = 0;
	tmp = alst;
	prt = ft_prt(str);
	prt2 = ft_prt2(str);
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, prt))
			g++;
		tmp = tmp->next;
	}
	tmp = add7_1(alst, prt, prt2, g);
	return (alst);
}
