/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:13:36 by msebbane          #+#    #+#             */
/*   Updated: 2022/09/25 12:24:45 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*nextword(char *line, int *j)
{
	int	i;
	int	start;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	start = i;
	while (line[i] && ft_isprint(line[i]) == 1)
	{
		i = verif_quotes(line, i);
	}
	*j += i;
	return (ft_strncpy(line + start, i - start));
}

char	*ft_strjoin_no_spc(const char *s1, const char *s2)
{
	char	*str;
	int		slen;
	int		i;
	int		j;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	slen = ft_strlen((char *)s1) + ft_strlen(s2);
	i = -1;
	j = -1;
	str = malloc(sizeof(char) * slen + 1);
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = '\0';
	free ((void *)s1);
	free ((void *)s2);
	return (str);
}

char	*ft_strncpy(char *s, int j)
{
	int		i;
	char	*str;

	i = 0;
	if (s == NULL || j == 0)
		return (NULL);
	str = malloc(sizeof(char) * j + 1);
	while (s[i] && i < j)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

t_parse	*ft_lstmove(t_parse *lst, int indice)
{
	int	s;

	if (lst)
	{
		s = 1;
		while (s < indice)
		{
			lst = lst->next;
			s++;
		}
	}
	return (lst);
}

void	print_global(void)
{
	int		i;
	t_parse	*tete;
	int		count;

	i = 0;
	count = 0;
	printf("debut de print global\n");
	tete = g_global.parse;
	while (tete)
	{
		printf("\nParse numero %i\n", count);
		printf("\nindice %i\n", tete->indice);
		printf("cmd = %s, flag = %s\n", tete->cmd, tete->flag);
		printf("infile = %i, outfile = %i\n", tete->infile, tete->outfile);
		while (tete->arg && tete->arg[i])
		{
			printf("argument n: %i = %s\n", i, tete->arg[i]);
			i++;
		}
		i = 0;
		tete = tete->next;
		count++;
	}
}
