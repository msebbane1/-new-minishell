/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:23:49 by lbally            #+#    #+#             */
/*   Updated: 2022/09/17 15:48:41 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	get_path(void)
{
	if (getcwd(NULL, 0) == NULL)
		perror("getcwd() error");
	else
		printf("%s\n", getcwd(NULL, 0));
}

char	*clean_str(char *path)
{
	int		i;
	int		j;
	char	*final;

	i = 0;
	j = 0;
	while (path[i] && !is_letter(path[i]))
		if (path[i] == ' ')
			i++;
	final = malloc(sizeof(char) * (ft_strlen(path) - i) + 1);
	while (path[i])
	{
		final[j++] = path[i];
		i++;
	}
	final[j] = '\0';
	return (final);
}

int	search_slash(char *path)
{
	int	i;

	i = ft_strlen(path);
	while (path[i] != '/')
		i--;
	return (i);
}

char	*add_slash(char *path)
{
	int		i;
	int		j;
	char	*new;

	new = malloc(sizeof(char) * ft_strlen(path) + 2);
	i = -1;
	j = 0;
	while (path[++i])
		new[j++] = path[i];
	new[j] = '/';
	j++;
	new[j] = '\0';
	return (new);
}

void	change_dir(t_parse *parse, t_list *alst)
{
	char	*new_path;
	char	*res;
	t_list	*new;
	//char	*old_path;

	new = alst;
	new_path = parse->arg[0];
	if (!parse->arg[0])
	{
		while (new)
		{
			if (!ft_strcmp(new->key, "HOME"))
			res = ft_strdup(new->content);
			new = new->next;
		}
		chdir(res);
		update_env(alst, res);
	}
	else if (!ft_strcmp(parse->arg[0], ".."))
	{
		//printf("path = %s\n", new_path);
		//printf("path = %s\n", );
		//old_path = getcwd(NULL, 0);
		new_path = ft_substr(getcwd(NULL, 0), 0, search_slash(getcwd(NULL, 0))); // segfault avec le dossier supprimer
		chdir((const char *)new_path);
		update_env(alst, new_path);
		//update_env(alst, old_path);
		//printf("new path = %s\n", new_path);
	}
	else if (!ft_strcmp(parse->arg[0], "~"))
	{
		while (new)
		{
			if (!ft_strcmp(new->key, "HOME"))
				res = ft_strdup(new->content);
			new = new->next;
		}
		chdir(res);
		update_env(alst, res);
	}
	else
	{
		res = add_slash(getcwd(NULL, 0));
		new_path = ft_strjoin(res, new_path);
		if (chdir(new_path) == -1)
		{
			printf("cd: %s: No such file or directory\n", parse->arg[0]);
			ft_substr(new_path, 3, ft_strlen(new_path));
		}
		else
			update_env(alst, new_path);
	}
	g_global.status = 0;
}



// printf("cd: %s: No such file or directory\n", parse->arg[0]);