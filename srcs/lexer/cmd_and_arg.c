/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_and_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:53:53 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/09/17 16:58:38 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_cmd_arg(char *line, int i, t_parse *tete)
{
	int		j;
	char	*nextw;

	j = i;
	nextw = nextword(line + i, &j);
	if (tete->first == 0)
	{
		tete->cmd = nextw;
		tete->first++;
	}
	else
	{
		tete->arg = ft_realloc2char(tete->arg, len_envp(tete->arg) + 1);
		ft_memcpy(tete->arg[len_envp(tete->arg) - 1], nextw, ft_strlen(nextw));
		free(nextw);
	}
	return (j);
}

char	**ft_realloc2char(char **src, int size)
{
	char	**dest;
	int		i;

	i = 0;
	if (src == NULL)
		return (NULL);
	dest = ft_calloc(sizeof(char *), size + 1);
	while (i < size)
	{
		dest[i] = ft_calloc(sizeof(char), (ft_strlen(src[i]) + 1));
		ft_memcpy(dest[i], src[i], ft_strlen(src[i]));
		i++;
	}
	free_tab(src);
	//free(src);
	return (dest);
}