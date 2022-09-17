/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:04:30 by msebbane          #+#    #+#             */
/*   Updated: 2022/09/12 17:45:12 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*tolower2(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] >= 'A' && cmd[i] <= 'Z')
			cmd[i] += 32;
		i++;
	}
	return (cmd);
}

int	count_arg(void)
{
	int	g;

	g = 0;
	if (g_global.parse->cmd)
		g++;
	if (g_global.parse->flag)
		g++;
	if (g_global.parse->arg)
		g++;
	return (g);
}
