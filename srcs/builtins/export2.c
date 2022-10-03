/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:14:26 by lbally            #+#    #+#             */
/*   Updated: 2022/10/03 23:38:49 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**export4(char **tab, t_exp *tmp, t_exp *atc)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = i + 1;
	tmp = atc;
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
	return (tab);
}

t_exp	*export3(char **tab, t_exp *tmp, int i)
{
	int		j;
	char	**tot;

	j = 1;
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
	free(tot);
	return (tmp);
}

char	**export2(char **tab, t_exp *tmp)
{
	int		j;
	int		i;

	j = 1;
	i = 0;
	while (tab[i])
	{
		if (ft_find_space(tab[i]))
			tmp = export3(tab, tmp, i);
		else
			tmp->name = tab[i];
		tmp = tmp->next;
		i++;
		j = 1;
	}
	return (tab);
}

void	port2(t_list *alst, t_parse *elem, int p, t_exp *atc)
{
	int	i;

	i = check(elem->arg[p]);
	if (i == 0)
		perror("export");
	else
	{
		if (i == 1)
		{
			add(atc, elem->arg[p]);
			add2(alst, elem->arg[p]);
		}
		else if (i == 2)
			add3(atc, elem->arg[p]);
		else
		{
			add4(atc, elem->arg[p]);
			add5(alst, elem->arg[p]);
		}
	}
}

void	port(t_exp *atc, t_list *alst)
{
	t_parse	*elem;
	int		i;
	int		p;

	elem = g_global.parse;
	i = 0;
	p = 0;
	if (elem->arg[0] == NULL)
		export(atc);
	else
	{
		while (elem->arg[p])
		{
			port2(alst, elem, p, atc);
			p++;
		}
	}
}
