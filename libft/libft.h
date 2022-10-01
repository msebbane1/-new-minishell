/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:28:26 by lbally            #+#    #+#             */
/*   Updated: 2022/10/01 15:01:06 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

typedef struct s_list
{
	struct s_list	*next;
	void			*content;
	char			*key;
}					t_list;

t_list				*ft_lstnew(void *content, char *key);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *));
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstadd_front(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_bzero(void *dest, size_t len);
void				ft_lstadd_front(t_list **alst, t_list *new);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t len);
void				*ft_memset(void *dest, int val, size_t len);
int					ft_isascii(int c);
int					ft_count(char const *s, char c);
int					ft_atoi(const char *nptr);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isprint(int c);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
int					ft_strncmp(const char *first, const char *second, size_t l);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_lstsize(t_list *lst);
char				*ft_trim(char const *s1, char c);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
char				*ft_strchr(const char *str, int c);
char				*ft_strdup(const char *s);
char				*ft_itoa(int n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strrchr(const char *str, int c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strtrim(char const *s1, char const *set);
//char				*ft_substr(char const *s, unsigned int start, size_t len);
char				**ft_split(char const *s, char c);
size_t				ft_strlen(const char *str);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);

#endif
