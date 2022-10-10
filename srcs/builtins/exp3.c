/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:47:51 by lbally            #+#    #+#             */
/*   Updated: 2022/10/10 13:51:41 by lbally           ###   ########.fr       */
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
	if (g == 0)
		tmp = add4_2(tmp, prt);
	else
		tmp = add4_3(tmp, prt);
	return (atc);
}

char	*ft_prt(char *str)
{
	char	*prt;
	int		i;

	i = 0;
	while ((str[i] != '+' && str[i + 1] != '=') && str[i] != '=')
		i++;
	prt = malloc(sizeof(char *) * i + 1);
	i = -1;
	while (str[i] != '+' && str[i] != '=')
	{
		prt[i] = str[i];
		i++;
	}
	prt[i] = '\0';
	return (prt);
}

char	*ft_prt2(char *str)
{
	char	*prt2;
	int		i;
	int		j;
	int		r;

	i = 0;
	j = 0;
	while (str[i] != '=')
		i++;
	r = i;
	while (str[i++])
		j++;
	prt2 = malloc(sizeof(char *) * j);
	j = 0;
	r++;
	while (str[r])
	{
		prt2[j] = str[r];
		r++;
		j++;
	}
	return (prt2);
}

t_exp	*add6_1(t_exp *tmp, char *prt, char *prt2, int g)
{
	t_exp	*new;

	new = malloc(sizeof(*tmp));
	if (g == 0)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->name = ft_strdup(prt);
		new->mean = ft_strdup(prt2);
		new->next = NULL;
	}
	else
	{
		while (ft_strcmp(tmp->name, prt))
			tmp = tmp->next;
		tmp->mean = ft_strdup(ft_strjoin_no_spc(tmp->mean, prt2));
	}
	return (tmp);
}

t_exp	*add6(t_exp *atc, char *str)
{
	t_exp	*tmp;
	char	*prt;
	char	*prt2;
	int		g;

	g = 0;
	tmp = atc;
	prt = ft_prt(str);
	prt2 = ft_prt2(str);
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, prt))
			g++;
		tmp = tmp->next;
	}
	tmp = add6_1(atc, prt, prt2, g);
	return (atc);
}
