/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remputils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:29:26 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/10/02 16:38:10 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	firtime(int t)
{
	if (t == 0)
		t++;
	return (t);
}

int	find(char c, char *search)
{
	int	i;

	i = -1;
	while (search && search[++i])
	{
		if (c == search[i])
			return (1);
	}
	return (0);
}

int	countbefc(char *str, char *search)
{
	int	i;

	i = -1;
	while (str && str[++i])
	{
		if (find(str[i], search) == 1)
			return (i);
	}
	return (i);
}

char	*findexp(t_exp *atc, char *str)
{
	t_exp	*tete;

	tete = atc;
	while (tete)
	{
		if (!ft_strcmp(tete->name, str))
		{
			return (tete->mean);
		}
		tete = tete->next;
	}
	return ("");
}

char	*ft_strdup2(const char *s, int size)
{
	int		i;
	char	*new;

	if (s == NULL || !s)
		return (NULL);
	if (size == 0)
		return ("");
	new = malloc(sizeof(char) * (size + 1));
	if (!new)
		return (0);
	i = 0;
	while (s[i] && i < size)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
