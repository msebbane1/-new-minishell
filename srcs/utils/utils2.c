/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:04:58 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/10/10 17:47:32 by vl-hotel         ###   ########.fr       */
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

int	isbuiltin(char *str)
{
	if (!ft_strcmp(str, "exit"))
		return (1);
	else if (!ft_strcmp(tolower2(str), "env"))
		return (1);
	else if (!ft_strcmp(tolower2(str), "echo"))
		return (1);
	else if (!ft_strcmp(tolower2(str), "pwd"))
		return (1);
	else if (!ft_strcmp(str, "cd"))
		return (1);
	else if (!ft_strcmp(str, "unset"))
		return (1);
	else if (!ft_strcmp(str, "export"))
		return (1);
	return (0);
}

void	wronglastcmd(t_parse *parse, t_list *alst)
{
	char	*lab;
	t_parse	*lst;

	lst = parse;
	while (lst)
	{
		if (lst->indice == len_parse())
		{
			if (!lst->cmd || lst->cmd == NULL || lst->cmd[0] == '\0')
				return ;
			if (isbuiltin(lst->cmd) == 1)
				return ;
			lab = check_path_access(alst, lst->cmd);
			if (lab == NULL)
				g_global.status = 127;
			else
			{
				if (g_global.status == 127)
					g_global.status = 0;
				free(lab);
			}
			return ;
		}
		lst = lst->next;
	}
}
