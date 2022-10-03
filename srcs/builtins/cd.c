/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:34:19 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/10/03 23:46:01 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	cd_only(t_list *alst)
{
	t_list	*tete;
	int		i;

	tete = alst;
	i = 0;
	while (tete)
	{
		if (!ft_strcmp(tete->key, "HOME"))
		{
			i = chdir(tete->content);
			return (i);
		}
		tete = tete->next;
	}
	ft_perror("cd", ": HOME not set\n", 1);
	return (i);
}

char	*findpwd(t_list	*alst)
{
	t_list	*list;

	list = alst;
	while (list)
	{
		if (!ft_strcmp(list->key, "PWD"))
			return (list->content);
		list = list->next;
	}
	return (ft_strdup(""));
}

static void	old_pwd(char *oldpwd, t_list *list, t_list *alst)
{
	free(list->content);
	if (oldpwd == NULL)
			list->content = findpwd(alst);
	else
		list->content = (oldpwd);
}

void	update_env(t_list *alst)
{
	t_list	*list;
	char	*oldpwd;
	char	*pwd;

	list = alst;
	oldpwd = NULL;
	pwd = getcwd(NULL, 0);
	while (list)
	{
		if (!ft_strcmp(list->key, "PWD"))
		{
			if (oldpwd == NULL)
				oldpwd = list->content;
			list->content = ft_strdup(pwd);
		}
		if (!ft_strcmp(list->key, "OLDPWD"))
			old_pwd(oldpwd, list, alst);
		list = list->next;
	}
	free(pwd);
}

void	cd(t_parse *parse, t_list *alst)
{
	int		res;

	res = 0;
	if (!parse->arg[0])
		res = (cd_only(alst));
	else if (ft_strlen(parse->flag) > 1)
		ft_perror("cd", "options are not handled\n", 1);
	else
	{
		res = chdir(parse->arg[0]);
	}
	if (res == -1)
	{
		ft_perror("cd:", parse->arg[0], 1);
		ft_perror(": ", "no such file or directory\n", 1);
	}
	update_env(alst);
	return ;
}
