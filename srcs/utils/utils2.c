/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:04:58 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/10/01 22:10:05 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_parse	*ft_parselast(t_parse *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_perror(char *s1, char *s2, int index)
{
	ft_putstr_fd(s1, 2);
	ft_putstr_fd(s2, 2);
	g_global.status = index;
}

void	ft_err_excve(t_parse *parse)
{
	perror("repere");
	if (parse->infile < 0)
	{
		perror(parse->sfile);
		return ;
	}
	if (parse->cmd[0] == '/')
		ft_perror(parse->cmd, ": No such file or directory\n", 127);
	else
		ft_perror(parse->cmd, ": command not found\n", 127);
}
