/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:24:42 by lbally            #+#    #+#             */
/*   Updated: 2022/09/16 16:16:45 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	count_pipe(char *line)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (line[i] == ' ' || line[i] == '|')
		i++;
	while (line[i] && line[i] != '|')
	{
		if (line[i] == '>')
			size++;
		i++;
	}
	return (size);
}

int	is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

char	**select_av(char *line)
{
	char	**new_av;

	new_av = ft_split(line, ' ');
	return (new_av);
}

int	search_pipe(char *line)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (line[i])
	{
		if (line[i] == '|')
			break ;
		i++;
	}
	res = i;
	return (res);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i] != '\0')
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
