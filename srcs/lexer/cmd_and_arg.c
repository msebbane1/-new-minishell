/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_and_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:53:53 by vl-hotel          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/09/19 17:30:59 by lbally           ###   ########.fr       */
=======
/*   Updated: 2022/09/19 15:14:05 by vl-hotel         ###   ########.fr       */
>>>>>>> dcf2f8051de5c3989ff3757fb82f3d997f88d938
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
		tete->arg = ft_realloc2char(tete->arg, len_envp(tete->arg) + 1, 0);
		// ft_memcpy(tete->arg[len_envp(tete->arg) - 1], nextw, ft_strlen(nextw));
		tete->arg[len_envp(tete->arg)] = nextw;
		// free(nextw);
	}
	return (j);
}

char	**ft_realloc2char(char **src, int size, int start)
{
	char	**dest;
	int		i;

	i = 0;
	if (src == NULL)
		return (NULL);
	dest = ft_calloc(sizeof(char *), size - start + 1);
	while (start < size)
	{
		dest[i] = ft_strdup(src[start]);
		i++;
		start++;
	}
	free_tab(src);
	return (dest);
}