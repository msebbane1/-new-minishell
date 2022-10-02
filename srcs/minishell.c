/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:03:27 by msebbane          #+#    #+#             */
/*   Updated: 2022/10/02 13:16:38 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

struct s_global	g_global;

char	*rl_gets(void)
{
	static char	*line_read;
	char		*res;

	if (line_read)
	{
		free (line_read);
		line_read = (char *) NULL;
	}
	line_read = readline ("minishell>> ");
	if (line_read && *line_read)
	{
		res = ft_strtrim(line_read, " \t\v\f\r");
		if (ft_strlen(res) > 0)
			add_history(res);
		free(res);
	}
	return (line_read);
}

char	*line_prompt(char *line, char **argv, int argc)
{
	(void)argc;
	(void)argv;
	if (!line)
		signal_exit();
	return (line);
}

void	init_global(void)
{
	g_global.parse = NULL;
	g_global.indice = malloc(sizeof(int) * 1);
	g_global.indice[0] = 0;
	g_global.here = 0;
}

int	main(int ac, char **av, char **envp)
{
	char	*line;
	t_exp	*atc;
	t_list	*alst;

	alst = NULL;
	atc = NULL;
	g_global.old_stdin = dup(STDIN_FILENO);
	g_global.old_stdout = dup(STDOUT_FILENO);
	insert_env(envp, &alst);
	insert_exp(envp, &atc);
	g_global.atc = atc;
	while (1)
	{
		init_signals();
		line = rl_gets();
		line = line_prompt(line, av, ac);
		init_global();
		// printf("LEXER\n");
		lexer(line);
		// printf("valeur de infile = |%s|\n", g_global.parse->sfile);
		// print_global();
		remplacev();
		// print_global();
		// printf("BRAIN\n");
		brain(alst, atc);
		// printf("FREE ALL\n");
		free_all();
		//free(g_global.indice);
	}
}

/*
Norme OK juste enlever lstmap

minishell>> ls | fsds | ls								perror
doit afficher : ldf: command not found

minishell>> sdf | fsds | sda
doit afficher 3 fois command not found ---> voir putstr fd

HERE :
<sfda
bash: sfda: No such file or directory

*/
