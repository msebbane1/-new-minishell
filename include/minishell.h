/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:05:10 by msebbane          #+#    #+#             */
/*   Updated: 2022/10/10 17:28:14 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
/* ************************* INCLUDES ************************* */

# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <termios.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include "../libft/libft.h"
# include <readline/history.h>
# include <readline/readline.h>

/* ************************ STRUCTURES ************************ */
typedef struct s_parse
{
	struct s_parse	*next;
	char			*cmd;
	char			**arg;
	char			*flag;
	char			*sfile;
	int				first;
	int				i;
	int				indice;
	int				infile;
	int				outfile;
	int				fd_kill;
	int				exit_code;
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

char	*rl_gets(void);
void	init_global(void);
char	*readline(const char *prompt);
void	insert_exp(char **envp, t_exp **atc);
void	insert_env(char **envp, t_list **alst);
char	*line_prompt(char *line, char **argv, int argc);

/* *************************** LEXER ************************** */

void	lexer(char *line);
char	*trflag(char *str);
void	msg_error(char *err);
t_parse	*ft_lstnew_parse(void);
char	*ft_strncpy(char *s, int j);
char	*nextword(char *line, int *j);
int		verif_quotes(char *str, int i);
t_parse	*ft_pipe(t_parse *tete, int *i);
void	heredoc(char *stop, t_parse *parse);
void	init_file(int fd, int i, t_parse *parse);
int		ft_flag(char *line, int i, t_parse *tete);
void	open_file(char *str, int i, t_parse *parse);
int		ft_cmd_arg(char *line, int i, t_parse *tete);
int		redirection_v(char *line, int i, t_parse *parse);
int		gestion_quotes(char *line, int i, t_parse *parse);
int		redirection_v2(char *line, int i, t_parse *parse);
void	ft_lstadd_back_parse(t_parse **alst, t_parse *new);
char	**ft_realloc2char(char **src, int size, int start);
char	*ft_strjoin_no_spc(const char *s1, const char *s2);

/* *************************** EXTEND ************************** */
void	remplacev(void);
char	*ft_expand(char *str);
int		find(char c, char *search);
char	*findexp(t_exp *atc, char *str);
int		countbefc(char *str, char *search);
char	*ft_strdup2(const char *s, int size);
char	*repelse(int *i, const char *res, char *str);
char	*repdollar(int *i, const char *res, char *str);
char	*repquotes(int *i, const char *res, char *str);
char	*repdblquotes(int *i, const char *res, char *str);
char	*repdollardbl(int *i, const char *res, char *str);
char	*dblquotesdollar(int *i, const char *res);
char	*else_dbl(int *i, const char *res, char *str, int *t);

/* *************************** BUILT-IN ************************** */

/* ****************** CD *******************/
int		cd_only(t_list *alst);
char	*findpwd(t_list	*alst);
void	update_env(t_list *alst);
void	cd(t_parse *parse, t_list *alst);

/* ***************** ECHO ******************/
void	ft_echo(t_parse *parse);
int		echo_check_flag(char *str);
int		helpecho(t_parse *parse, int *j);

/* ****************** ENV ******************/
void	print_list(t_list *alst);

/* ***************** EXIT ******************/
int		ft_exit(char **str);

/* **************** EXPORT *****************/
int		check(char *str);
int		check2(char *str, int i, int j);
int		check3(int j, int t);
void	export(t_exp *atc);
void	print_exp(t_exp *atc);
int		ft_find_space(char *str);
t_exp	*add(t_exp *atc, char *str);	
t_exp	*add3(t_exp *atc, char *str);
t_exp	*add4(t_exp *atc, char *str);
t_list	*add5(t_list *alst, char *str);
t_exp	*add6(t_exp *atc, char *str);
t_list	*add7(t_list *alst, char *str);
t_exp	*add_3(t_exp *tmp, char **prt);
t_list	*add2(t_list *alst, char *str);
void	add2_1(t_list *tmp, char **prt, int g);
t_list	*add2_2(t_list *tmp, char **prt);
void	port(t_exp *atc, t_list *alst);
int		ismore(char *lala, char *lolo);
t_exp	*add4_2(t_exp *tmp, char **prt);
t_exp	*add4_3(t_exp *tmp, char **prt);
t_list	*add5_3(t_list *tmp, char **prt);
t_list	*add5_2(t_list *tmp, char **prt);
void	export2(char **tab, t_exp *tmp);
char	**export5(char **tab, t_exp *atc);
char	*ft_concatenate(char *line, char *bf);
t_exp	*add_2(t_exp *tmp, char **prt, int g);
char	*ft_concatenate(char *line, char *bf);
char	**export4(char **tab);
char	*ft_prt(char *str);
char	*ft_prt2(char *str);

/* **************** UNSET ******************/
void	unset(t_list **alst, t_exp **atc);
/* ****************** PWD ******************/
void	ft_pwd(void);
/* *************************** EXEC ************************** */

int		len_parse(void);
char	**enov(t_list *alst);
int		exitstatus(int status);
int		cmdin_parse(t_parse *parse);
void	brain(t_list *alst, t_exp *atc);
void	wronglastcmd(t_parse *lst, t_list *alst);
char	*check_path_access(t_list *alst, char *cmd);
void	dupfunction(t_parse *elem, int *fd, int fdin);
void	execlab(t_parse *elem, t_list *alst, t_exp *atc);
void	ft_execve(t_parse *parse, t_list *alst, char **lab);
char	**check_elem(t_parse *parse, t_list *alst, char **lab);
void	ft_fils(t_parse *elem, t_list *alst, t_exp *atc, int fdin);
void	exec_cmd(t_parse *parse, t_list *alst, t_exp *atc, char **lab);
void	exec_cmdmulti(t_parse *parse, t_list *alst, t_exp *atc, char **lab);

/* *************************** SIGNAL ************************** */
void	signal_exit(void);
void	init_signals(void);
void	ft_signal(int signum);
void	echo_control_seq(int c);
void	ft_signalquit(int signum);

/* ************************** FREE-ALL ************************* */
void	free_all(void);
void	free_tab(char **tab);
void	free_atc(t_exp *alst);

/* *************************** UTILS ************************** */
char	*tolower2(char *cmd);
int		len_envp(char **envp);
int		back_slash(char *str);
t_parse	*ft_parselast(t_parse *lst);
void	ft_err_excve(t_parse *parse);
int		ft_cmpchar(char s1, char s2);
char	*ft_concatenate(char *line, char *bf);
void	ft_perror(char *s1, char *s2, int index);
int		ft_strcmp(const char *s1, const char *s2);

/* *************************** TEST ************************** */
void	print_global(void);
void	print_tab(char **tab);

#endif
