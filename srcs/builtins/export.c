/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 07:16:25 by lbally            #+#    #+#             */
/*   Updated: 2022/10/10 14:04:49 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_concatenate(char *line, char *bf)
{
	char		*temp;

	temp = line;
	line = ft_strjoin(temp, bf);
	free(temp);
	return (line);
}

int	ft_find_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int	check(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	return (check2(str, i, j));
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
	t_exp	*tmp2;
	char	**tab;
	int		i;

	tmp2 = atc;
	list = atc;
	i = 0;
	while (tmp2)
	{
		tmp2 = tmp2->next;
		i++;
	}
	tab = (char **)malloc(sizeof(char *) * (i + 1));
	tab = export5(tab, atc);
	tab = export4(tab);
	export2(tab, atc);
	print_exp(atc);
	free_tab(tab);
	g_global.status = 0;
}
