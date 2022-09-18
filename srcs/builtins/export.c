/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 07:16:25 by lbally            #+#    #+#             */
/*   Updated: 2022/09/18 16:20:18 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_concatenate(char *line, char *bf)
{
	char		*temp;

	temp = NULL;
	temp = line;
	line = ft_strjoin(temp, bf);
	free(temp);
	temp = NULL;
	return (line);
}

int	check(void)
{
	t_parse	*pp;
	int		i;
	int		j;
	int		g;

	pp = g_global.parse;
	g = 0;
	i = 0;
	j = 0;
	while (pp->arg[g][i])
	{
		if (!is_letter(pp->arg[g][0]))
			return (0);
		if (pp->arg[g][i] == ' ')
			return (0);
		if (pp->arg[g][i] == '=')
			j++;
		i++;
	}
	if (j == 0)
		return (2);
	if (j > 1)
		return (3);
	return (1);
}

int	ismore(char *lala, char *lolo)
{
	int	i;

	i = 0;
	while (lala[i] == lolo[i])
		i++;
	if (lala[i] < lolo[i])
		return (1);
	return (0);
}

void	export(t_exp *atc)
{
	t_exp	*list;
	t_exp	*tmp;
	t_exp	*tmp2;
	char	**tab;
	char	**tot;
	char	*temp;
	int		i;
	int		j;

	tmp2 = atc;
	list = atc;
	tmp = atc;
	i = 0;
	while (tmp2)
	{
		tmp2 = tmp2->next;
		i++;
	}
	tab = (char **)malloc(sizeof(char *) * i + 1);
	i = 0;
	while (list)
	{
		list->name = ft_concatenate(list->name, "=");
		tab[i] = ft_concatenate(list->name, list->mean);
		list = list->next;
		i++;
	}
	tab[i] = NULL;
	i = 0;
	j = i + 1;
	while (tab[i])
	{
		while (tab[j])
		{
			if (!ismore(tab[i], tab[j]))
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	i = 0;
	j = 1;
	while (tab[i])
	{
		tot = ft_split(tab[i], '=');
		tmp->name = tot[0];
		tmp->mean = tot[1];
		if (tot[2] != NULL)
		{
			tmp->mean = ft_concatenate(tmp->mean, "=");
			tmp->mean = ft_concatenate(tmp->mean, tot[j + 1]);
			j++;
			while (tot[j + 1] != NULL)
			{
				tmp->mean = ft_concatenate(tmp->mean, "=");
				tmp->mean = ft_concatenate(tmp->mean, tot[j + 1]);
				j++;
			}
		}
		tmp = tmp->next;
		i++;
		j = 1;
	}
	print_exp(atc);
	g_global.status = 0;
}

void	port(t_exp *atc, t_list *alst)
{
	t_parse	*elem;
	int		i;

	elem = g_global.parse;
	i = 0;
	if (elem->arg[elem->i] == NULL)
		export(atc);
	else
	{
		i = check();
		if (i == 0)
			perror("export");
		else
		{
			if (i == 1)
			{
				add(atc, elem->arg[elem->i]);
				add2(alst, elem->arg[elem->i]);
			}
			else if (i == 2)
				add3(atc, elem->arg[elem->i]);
			else
			{
				add4(atc, elem->arg[elem->i]); // export 2 fois ajouter aussi dans env
				add5(alst, elem->arg[elem->i]);
			}	
		}		
	}
}