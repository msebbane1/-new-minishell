/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:05:10 by msebbane          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/09/18 16:59:58 by lbally           ###   ########.fr       */
=======
/*   Updated: 2022/09/18 17:09:39 by vl-hotel         ###   ########.fr       */
>>>>>>> 76db8d65bccd4a271a7cc2892b5d1f7577ee2789
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
/* ************************* INCLUDES ************************* */

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include "../libft/libft.h"
# include <sys/types.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>

/* ************************ STRUCTURES ************************ */
typedef struct s_parse
{
	struct s_parse	*next;
	char			*cmd;
	char			**arg;
	char			*flag;
	int				first;
	int				i;
	int				infile;
	int				outfile;
	int				fd_kill;
}				t_parse;

typedef struct s_exp
{
	char			*name;
	void			*mean;
	struct s_exp	*next;

}	t_exp;

typedef struct s_global
{
	t_parse		*parse;
	int			status;
	int			nb_cmd;
	char		**env;
}	t_global;

extern struct s_global	g_global;

int		is_alpha(char c);
int		ft_strcmp(const char *s1, const char *s2);
int		len_envp(char **envp);
int		is_letter(char c);
int		len_list(t_list *alst);
int		is_redir(char *cmd);
int		is_pipe(char *cmd);
int		is_option(char *cmd);
int		count_letter(char *cmd, int i);
int		check_char(char c);
int		count_pipe(char *line);
int		search_pipe(char *line);
int		len_str(char **tab);
int		ft_cmpchar(char s1, char s2);
int		count_arg(void);
int		back_slash(char *str);

char	**putenv_in_tab(t_list *alst);
char	**select_av(char *line);
char	*ft_strcpy(char *s, char *str);
char	*concat_wspace2(char *s1, char *s2);
char	*add_slash(char *path);
char	*rl_gets(void);
char	*clean_str(char *path);
char	*get_path_redirection(char *cmd, int i);
char	*sub_arg(char *line, int i);
char	*cut_arg(char *line, int i);
char	*sub_path_direction(char *cmd, int i);
char	*cut_arg(char *line, int i);
char	*check_path_access(t_list *alst, char *cmd);
char	*ft_concatenate(char *line, char *bf);
char	*tolower2(char *cmd);
<<<<<<< HEAD
char	*dollar(char *str, int c);
char	**ft_realloc2char(char **src, int size);
=======
char	*dollar(char *str);
>>>>>>> 76db8d65bccd4a271a7cc2892b5d1f7577ee2789

void	insert_env(char **envp, t_list **alst);
void	insert_exp(char **envp, t_exp **atc);
void	print_list(t_list *alst);
void	add_back(t_parse **parse, t_parse *new);
void	get_path(void);
void	print_arg(void);
void	update_env(t_list *alst, char *path);
void	my_exec(t_list *alst, t_exp *atc);
void	print_list(t_list *alst);
void	print_exp(t_exp *atc);
//void	dollar(t_list *alst, char *str);
void	ft_signal(int signum);
void	signal_exit(void);
void	signals(void);
char	**check_elem(t_parse *parse, t_list *alst, char **lab);
void	cmp_cmd(t_parse *parse, t_list *alst, t_exp *atc);
void	ft_execve(t_parse *parse, t_list *alst, char **lab);
void	line_prompt(char *line, char **argv, int argc);
void	ft_quote(char *cmd);
void	exec_cmd(t_parse *parse, t_list *alst, t_exp *atc, char **lab);
void	exec(t_parse *parse, t_list *alst, int *cmd);
void	ft_execve(t_parse *parse, t_list *alst, char **lab);
void	my_exec(t_list *alst, t_exp *atc);
void	flagi(t_parse *parse, t_exp *atc);
void	argi(t_parse *parse, t_exp *atc, char *arg, int w);
void	cmdi(t_parse *parse, t_exp *atc);

char	*readline(const char *prompt);
int		add_history(const char *string_for_history);
int		rl_on_new_line(void);
void	rl_display(void);
void	rl_replace_line(const char *buffer, int something);
void	rl_clear_history(void);

t_exp	*add(t_exp *atc, char *str);	
t_list	*add2(t_list *alst, char *str);
t_exp	*add3(t_exp *atc, char *str);
t_exp	*add4(t_exp *atc, char *str);
t_list	*add5(t_list *alst, char *str);
t_parse	*remplace(t_parse *parse, t_exp *atc);

/* *************************** INIT ************************** */

void	init_global(char **envp);

/* *************************** LEXER ************************** */

void	msg_error(char *err);
int		count_pipe_v(char *line);
void	init_file(int fd, int i, t_parse *parse);
void	open_file(char *str, int i, t_parse *parse);
char	*nextword(char *line, int *j);
char	*ft_strncpy(char *s, int j);
int		redirection_v(char *line, int i, t_parse *parse);
int		ft_flag(char *line, int i, t_parse *tete);
t_parse	*ft_lstmove(t_parse *lst, int indice);
void	lexer(char *line);
char	*ft_strjoin_no_spc(const char *s1,const char *s2);
t_parse	*ft_lstnew_parse(void);
char	**ft_realloc2char(char **src, int size, int start);
int		ft_cmd_arg(char *line, int i, t_parse *tete);
void	heredoc(char *stop, t_parse *parse);
void	ft_lstadd_back_parse(t_parse **alst, t_parse *new);
int		verif_quotes(char *str, int i);
int 	gestion_quotes(char *line, int i, t_parse *parse);
char	*trflag(char *str);
int     redirection_v(char *line, int i, t_parse *parse);
int		redirection_v2(char *line, int i, t_parse *parse);

/* *************************** TEST ************************** */

void	print_global(void);

/* *************************** BUILT-IN ************************** */
int		echo_check_flag(char *str);
void	ft_echo(t_parse *parse);
int		ft_exit(char **str);
void	ft_pwd(t_list *alst);
void	change_dir(t_parse *parse, t_list *alst);
void	built_in_cd(char *path);
void	destroy(t_list **alst, t_exp **atc);
void	port(t_exp *atc, t_list *alst);

/* *************************** FREE-ALL ************************** */
void	free_all(void);
void	free_tab(char **tab);
void	free_lst(t_list *alst);
void	free_atc(t_exp *alst);

#endif
