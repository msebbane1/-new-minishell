/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:13:36 by msebbane          #+#    #+#             */
/*   Updated: 2022/10/01 20:17:01 by vl-hotel         ###   ########.fr       */
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
	while (line[i] && ft_isprint(line[i]) == 1 && find(line[i], "<>|") == 0)
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
	str = malloc(sizeof(char) * (slen + 1));
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
	str = malloc(sizeof(char) * (j + 1));
	while (s[i] && i < j)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
