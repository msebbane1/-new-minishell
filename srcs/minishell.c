/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:03:27 by msebbane          #+#    #+#             */
/*   Updated: 2022/09/28 20:15:14 by msebbane         ###   ########.fr       */
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
	g_global.parse = malloc(sizeof(t_parse)); // free toute la struct avant de free global.parse
	g_global.indice = malloc(sizeof(int) * 1);
	g_global.indice[0] = 0;
	g_global.here = 0;
	free(g_global.parse);
}

int	main(int ac, char **av, char **envp)
{
	char	*line;
	t_exp	*atc;
	t_list	*alst;

	alst = NULL;
	g_global.old_stdin = dup(STDIN_FILENO);
	g_global.old_stdout = dup(STDOUT_FILENO);
	insert_env(envp, &alst);
	insert_exp(envp, &atc);
	while (1)
	{
		init_signals();
		line = rl_gets();
		line = line_prompt(line, av, ac);
		init_global();
		lexer(line);
		// print_global();
		remplace(g_global.parse, atc);
		brain(alst, atc);
		free_all();
		free(g_global.parse);
	}
}

/*
A FIX :

ls - == doit afficher ls: -: No such file or directory
- Multi here_doc <<q <<w <<e
- Gerer les termios

- CD :																	A REGLER(pipe exceve: MARIE)
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
(valgrind --leak-check=full ./minishell)


NEW PROBLEMES:
env -i = segfault														probleme dans check_path_access									OK
env -i -> export	trop de freee															
cat-d
enlever les espace ou tab dans l'historique
echo $?																	probleme dans extend
Unset path -> pwd = segfault
cat + ctr-c	ou ctr-\ 		double prompteur								signaux
Here_doc 		si signaux, segfault										signaux
here_doc + ctr-D		segfault											Signaux
Unset PATH puis commande = segfault																										OK
export 		trop de freee
export aaaaaa		naffiche pas
export aaaaa=bs puis export aaaaa=fdfdsfds   ne remplace pas
export a=b c=fd d j=t ne fait que le premier export et pas les autres
					
*/