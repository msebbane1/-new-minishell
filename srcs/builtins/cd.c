/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:34:19 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/09/21 16:34:24 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	cd_only(t_list *alst)
{
	t_list	*tete;
	int		i;
	
	tete =  alst;
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
	printf("minishell: cd: HOME not set\n");
	return (i);
}

char *findpwd(t_list	*alst)
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

void	update_env2(t_list *alst)
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
		{
			free(list->content);
			if (oldpwd == NULL)
				list->content = findpwd(alst);
			else
				list->content = (oldpwd);
		}
		list = list->next;
	}
}

void	cd(t_parse *parse, t_list *alst)
{
	int		res;

	res = 0;
	if (!parse->arg[0])
		res = (cd_only(alst));
	else if (ft_strlen(parse->flag) > 1)
		printf("minishell: cd: options are not handled\n");
	else
	{
		res = chdir(parse->arg[0]);
	}
	if (res == -1)
	{
		printf("minishell: cd: %s: no such file or directory\n", parse->arg[0]);
	}
	update_env2(alst);
	return ;
}