/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:05:10 by msebbane          #+#    #+#             */
/*   Updated: 2022/09/30 02:47:17 by vl-hotel         ###   ########.fr       */
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
# include <sys/ioctl.h>
# include <fcntl.h>
# include <termios.h>
# include <sys/stat.h>

/* ************************ STRUCTURES ************************ */
typedef struct s_parse
{
	struct s_parse	*next;
	char			*cmd;
	char			**arg;
	char			*flag;
	int				first;
	int				i;
	int				indice;
	int				infile;
	int				outfile;
	int				fd_kill;
}				t_parse;

typedef struct s_remp
{
	int			i;
	int			d;
	int			h;
	int			g;
	int			r;
	int			c;
	int			w;
}				t_remp;

typedef struct s_exp
{
	char			*name;
	void			*mean;
	struct s_exp	*next;

}	t_exp;

typedef struct s_global
{
	t_parse		*parse;
	t_exp		*atc;
	int			status;
	int			nb_cmd;
	int			here;
	int			*indice;
	char		**env;
	int			old_stdin;
	int			old_stdout;
}	t_global;

extern struct s_global	g_global;

int		rl_on_new_line(void);
void	rl_replace_line(const char *buffer, int something);

/* *************************** INIT ************************** */

void	init_global(void);
void	insert_env(char **envp, t_list **alst);
void	insert_exp(char **envp, t_exp **atc);
char	*line_prompt(char *line, char **argv, int argc);
char	*readline(const char *prompt);
char	*rl_gets(void);

/* *************************** LEXER ************************** */

void	msg_error(char *err);
void	init_file(int fd, int i, t_parse *parse);
void	open_file(char *str, int i, t_parse *parse);
char	*nextword(char *line, int *j);
char	*ft_strncpy(char *s, int j);
int		ft_flag(char *line, int i, t_parse *tete);
void	lexer(char *line);
char	*ft_strjoin_no_spc(const char *s1, const char *s2);
t_parse	*ft_lstnew_parse(void);
char	**ft_realloc2char(char **src, int size, int start);
int		ft_cmd_arg(char *line, int i, t_parse *tete);
void	heredoc(char *stop, t_parse *parse);
void	ft_lstadd_back_parse(t_parse **alst, t_parse *new);
int		verif_quotes(char *str, int i);
int		gestion_quotes(char *line, int i, t_parse *parse);
char	*trflag(char *str);
int		redirection_v(char *line, int i, t_parse *parse);
int		redirection_v2(char *line, int i, t_parse *parse);

/* *************************** EXTEND ************************** */
void	flagi(t_parse *parse, t_exp *atc, t_remp *remp);
void	flagi5(t_remp *remp, t_parse *parse);
char	*flagi6(t_remp *remp, t_parse *parse);
void	flagi8(t_remp *remp, t_parse *parse, char *str);
void	flagi9(t_remp *remp, t_parse *parse);
char	*flagi_10(t_remp *remp, t_parse *parse, char *str, char *lala);
void	flagi_11(t_remp *remp, t_parse *parse, char *str, t_exp *atc);
void	flagi_12(t_remp *remp, t_parse *parse, char *str, t_exp *atc);
void	argi(t_parse *parse, t_exp *atc, char *arg, t_remp *remp);
char	*argi5(char *arg, t_remp *remp, char *dolli);
char	*argi7(t_remp *remp, char *dolli, t_exp *atc);
void	argi8(char *arg, t_remp *remp, char *dolli, t_parse *parse);
int		argi_11(char *arg, t_remp *remp, char *dolli, t_parse *parse);
void	cmdi(t_parse *parse, t_exp *atc, t_remp *remp);
char	*cmdi5(t_parse *parse, t_remp *remp, char *doll);
void	cmdi7(t_parse *parse, t_remp *remp, char *doll);
void	cmdi_10(t_parse *parse, t_remp *remp, char *doll, t_exp *atc);
void	cmdi_11(t_parse *parse, t_remp *remp, char *doll, t_exp *atc);
t_parse	*remplace(t_parse *parse, t_exp *atc);
char	*dollar(char *str, int c);
void	init(t_remp *remp);

/* *************************** REMPVAL ************************** */
void	remplacev(void);
char	 *ft_expand(char *str);
int		find(char c, char *search);
int		countbefc(char *str, char *search);
char 	*findexp(t_exp *atc, char *str);
char	*ft_strdup2(const char *s, int size);
char	*repelse(int *i, const char *res, char *str);
char	*repquotes(int *i, const char *res, char *str);
char	*repdblquotes(int *i, const char *res, char *str);
char	*repdollar(int *i, const char *res, char *str);

/* *************************** BUILT-IN ************************** */
/* ****************** CD *******************/
void	cd(t_parse *parse, t_list *alst);
int		cd_only(t_list *alst);
void	update_env(t_list *alst);
char	*findpwd(t_list	*alst);

/* ****************** ECHO *******************/
int		echo_check_flag(char *str);
void	ft_echo(t_parse *parse);

/* ****************** ENV *******************/
void	print_list(t_list *alst);

/* ****************** EXIT *******************/
int		ft_exit(char **str);

/* ****************** EXPORT *******************/
void	print_exp(t_exp *atc);
t_exp	*add(t_exp *atc, char *str);	
t_exp	*add_2(t_exp *tmp, char **prt, int g);
t_exp	*add_3(t_exp *tmp, char **prt);
t_list	*add2(t_list *alst, char *str);
t_exp	*add3(t_exp *atc, char *str);
t_exp	*add4(t_exp *atc, char *str);
t_exp	*add4_2(t_exp *tmp, char **prt);
t_exp	*add4_3(t_exp *tmp, char **prt);
t_list	*add5(t_list *alst, char *str);
t_list	*add5_2(t_list *tmp, char **prt);
t_list	*add5_3(t_list *tmp, char **prt);
void	port(t_exp *atc, t_list *alst);
void	export(t_exp *atc);
char	**export2(char **tab, t_exp *tmp);
char	**export4(char **tab, t_exp *tmp, t_exp *atc);
char	**export5(char **tab, t_exp *atc);
char	*ft_concatenate(char *line, char *bf);
int		check(char *str);
int		ft_find_space(char *str);
char	*ft_concatenate(char *line, char *bf);
int		ismore(char *lala, char *lolo);

/* ****************** UNSET *******************/
void	unset(t_list **alst, t_exp **atc);
/* ****************** PWD *******************/
void	ft_pwd(void);
/* *************************** EXEC ************************** */

void	brain(t_list *alst, t_exp *atc);
int		len_parse(void);
int		cmdin_parse(t_parse *parse);
void	execlab(t_parse *elem, t_list *alst, t_exp *atc);
void	ft_fils(t_parse *elem, t_list *alst, t_exp *atc, int fdin);
void	exec_cmdmulti(t_parse *parse, t_list *alst, t_exp *atc, char **lab);
char	**enov(t_list *alst);
char	**check_elem(t_parse *parse, t_list *alst, char **lab);
void	ft_execve(t_parse *parse, t_list *alst, char **lab);
void	exec_cmd(t_parse *parse, t_list *alst, t_exp *atc, char **lab);
char	*check_path_access(t_list *alst, char *cmd);
void	dupfunction(t_parse *elem, int *fd, int fdin);

/* *************************** SIGNAL ************************** */
void	ft_signal(int signum);
void	ft_signalquit(int signum);
void	signal_exit(void);
void	init_signals(void);
void	echo_control_seq(int c);

/* *************************** FREE-ALL ************************** */
void	free_all(void);
void	free_tab(char **tab);
void	free_lst(t_list *alst);
void	free_atc(t_exp *alst);

/* *************************** UTILS ************************** */
int		ft_strcmp(const char *s1, const char *s2);
int		len_envp(char **envp);
int		ft_cmpchar(char s1, char s2);
int		back_slash(char *str);
char	*ft_concatenate(char *line, char *bf);
char	*tolower2(char *cmd);

/* *************************** TEST ************************** */

void	print_global(void);
void	print_tab(char **tab);

#endif
