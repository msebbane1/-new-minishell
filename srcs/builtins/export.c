/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 07:16:25 by lbally            #+#    #+#             */
/*   Updated: 2022/09/28 21:04:31 by lbally           ###   ########.fr       */
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
	while (str[i])
	{
		if (!ft_isalpha(str[0]))
			return (0);
		if (str[i] == ' ')
			return (0);
		if (str[i] == '=')
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
	int		i;

	tmp2 = atc;
	list = atc;
	tmp = atc;
	i = 0;
	while (tmp2->next != NULL)
	{
		tmp2 = tmp2->next;
		i++;
	}
	tab = (char **)malloc(sizeof(char *) * (i + 1));
	tab = export5(tab, atc);
	tab = export4(tab, tmp, atc);
	tab = export2(tab, tmp);
	print_exp(atc);
	g_global.status = 0;
}
