/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:03:27 by msebbane          #+#    #+#             */
/*   Updated: 2022/09/18 19:48:25 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

struct s_global	g_global;

char	*rl_gets(void)
{
	static char	*line_read;

	if (line_read)
	{
		free (line_read);
		line_read = (char *) NULL;
	}
	line_read = readline ("minishell>> ");
	if (line_read && *line_read)
		add_history (line_read);
	return (line_read);
}

void	line_prompt(char *line, char **argv, int argc)
{
	(void)argc;
	if (!line)
		signal_exit();
	line = ft_strtrim(line, " "); // leaks
	argv = ft_split(line, ' '); // leaks
}

void	init_global(char **envp)
{
	g_global.parse = malloc(sizeof(t_parse)); // free toute la struct avant de free global.parse
	g_global.env = envp;
}

int	main(int ac, char **av, char **envp)
{
	char	*line;
	t_exp	*atc;
	t_list	*alst;

	alst = NULL;
	insert_env(envp, &alst);
	insert_exp(envp, &atc);
	signals();
	while (1)
	{
		line = rl_gets();
		line_prompt(line, av, ac);
		init_global(envp);
		lexer(line);
		print_global();
		remplace(g_global.parse, atc);
		printf("test = |%s|\n", g_global.parse->cmd);
		printf("test = |%s|\n", g_global.parse->flag);
		printf("test = |%s|\n", g_global.parse->arg[0]);
		my_exec(alst, atc);
		free_all();
		//killhere();
		//free(g_global.parse);
		//free_lst(alst);
		//free_atc(atc);
		//free(line);
	}
}

/*
void	free_lst(t_list *alst)
{
	t_list	*tmp;

	while (alst)
	{
		tmp = alst->next;
		free(alst->content);
		free(alst->key);
		free(alst);
		alst = tmp;
	}
}

void	free_atc(t_exp *alst)
{
	t_exp	*tmp;

	while (alst)
	{
		tmp = alst->next;
		free(alst->name);
		free(alst->mean);
		free(alst);
		alst = tmp;
	}
}*/

/*
A FIX :

- Multi here_doc <<q <<w <<e
- Gerer les termios

- CD :
	- cd .. apres la suppression d'un fichier creer segfault																		A REGLER(pipe exceve: MARIE)
	si je unset home puis que je fais cd et enfin pwd ---> cela segfault
- EXPORT :
	- a=b=d=c ----> sáffiche dans env 																								OKKKKKKKKK
	- quand il y a la meme lettre ne dois pas s'afficher 2 fois dois remplacer le a- export 2 fois le meme (a gerer)				OKKKKKKKKK
- HERE DOC :
	- >>a ls ---> doit faire ls que avec la 1ere lettre (ex = asdf execute quand meme la cmd)										PAS COMPRIS
	- << a ls | << b ls | << v ls ------> affiche 3 fois ls dois afficher qu'une fois												A REGLER(pipe exceve: MARIE)
	- << a ls --> ctrl\D -> doit executer la commande(ici segfault) ctrl\C doit quitter le here_doc
	
- $ :
	- $$ ne dois pas etre gerer (ne rien faire pour le comportement)
	- $? ne fonctionne pas correctement
	- $$ ne dois pas etre gerer (ignorer)
- ECHO :
	- echo \n sans guillemets = n
	- echo avec $
	- echo sfsdfsd'sdfdsf' et "" == sfsdfsdsdfdsf
	- exp'ort'  et l"s" doit fonctionner aussi
	- a=b=d=v dafficher dans env
	- echo "salut" "les" "enfants" (ne fais pas d'espace)
	salut les enfants

- SIMPLE QUOTE + DOUBLE QUOTES
	-simple quote et double quote + avec echo (a faire)
	echo 'PATH' --> PATH
	echo '$PATH'--> $PATH
	echo "$PATH" --> affiche le path
	echo $PATH --> affiche le path
	- ec"ho" ou l's' = ne trouve pas la commande
	-l' --> ne dois pas segfault
	- echo "fsdfsd" ou 'asd' --> segfault vers gestion_quotes ??

- SIGNAUX :
	cat + ctrl \ doit afficher = ^\Quit: 3
	exit sur la meme ligne
- PIPE :
	- ls | cat doit executer qu'une commande																						A REGLER(pipe exceve: MARIE)
	- mkdir test1 | ls ----> segfault
	- mkdir "test1" | ls --> ne dois pas creer un dossier avec les quotes

+ LEAKS

*/
