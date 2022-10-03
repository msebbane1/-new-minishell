/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:19:04 by msebbane          #+#    #+#             */
/*   Updated: 2022/10/03 20:23:14 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**split_path(t_list *alst, char **tab_path)
{
	while (alst != NULL)
	{
		if (!strcmp(alst->key, "PATH"))
		{
			tab_path = ft_split(alst->content, ':');
			break ;
		}
		alst = alst->next;
	}
	return (tab_path);
}

static char	*check_path2(char	**tab_path, char	*test, char	*path)
{
	free_tab(tab_path);
	free(test);
	return (path);
}

char	*check_path_access(t_list *alst, char *cmd)
{
	char	**tab_path;
	char	*path;
	char	*test;
	int		i;

	i = -1;
	if (!access(cmd, F_OK))
		return (ft_strdup(cmd));
	tab_path = NULL;
	tab_path = split_path(alst, tab_path);
	while (tab_path && tab_path[++i])
	{
		if (!back_slash(tab_path[i]))
		{
			test = ft_strjoin(tab_path[i], "/");
			path = ft_strjoin(test, cmd);
		}
		if (!access(path, F_OK))
			return (check_path2(tab_path, test, path));
		free(test);
		free(path);
	}
	free_tab(tab_path);
	g_global.status = 127;
	return (NULL);
}
