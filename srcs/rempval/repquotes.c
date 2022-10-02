/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repquotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:11:27 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/10/02 16:46:49 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*repquotes(int *i, const char *res, char *str)
{
	int		size;
	char	*result;
	char	*tmp;

	size = countbefc(str + *i, "\'");
	if (size == 0)
	{
		*i += 1;
		return ((char *)res);
	}
	tmp = ft_strdup2(str + *i, size);
	result = ft_strjoin_no_spc(res, tmp);
	*i += size + 1;
	return (result);
}

char	*repdblquotes(int *i, const char *res, char *str)
{
	char	*result;
	int		t;

	t = 0;
	while (str[*i] != '\"' && str[*i])
	{
		if (str[*i] == '$')
		{
			*i += 1;
			t = firtime(t);
			if (t == 1)
				result = repdollardbl(i, res, str);
			else
				result = repdollardbl(i, result, str);
		}
		else
			result = else_dbl(i, res, str, t);
	}
	*i += 1;
	return (result);
}

char	*repdollardbl(int *i, const char *res, char *str)
{
	int		size;
	char	*result;
	char	*tmp;

	if (str[*i] == '?')
	{
		*i += 1;
		tmp = ft_strjoin_no_spc(res, ft_itoa(g_global.status));
		return (tmp);
	}
	if (str[*i] == '\"' || str[*i] == ' ')
	{
		*i += 1;
		tmp = ft_strjoin_no_spc(res, ft_strdup("$"));
		return (tmp);
	}
	size = countbefc(str + *i, "\'\"$ ");
	if (size == 0)
		return ((char *)res);
	tmp = ft_strdup2(str + *i, size);
	result = ft_strdup(findexp(g_global.atc, tmp));
	result = ft_strjoin_no_spc(res, result);
	*i += size;
	free(tmp);
	return (result);
}

char	*repdollar(int *i, const char *res, char *str)
{
	int		size;
	char	*result;
	char	*tmp;

	if (str[*i] == '?')
	{
		*i += 1;
		tmp = ft_strjoin_no_spc(res, ft_itoa(g_global.status));
		return (tmp);
	}
	if (str[*i] == '\0')
	{
		*i += 1;
		tmp = ft_strjoin_no_spc(res, ft_strdup("$"));
		return (tmp);
	}
	size = countbefc(str + *i, "\'\"$ ");
	if (size == 0)
		return ((char *)res);
	tmp = ft_strdup2(str + *i, size);
	result = ft_strdup(findexp(g_global.atc, tmp));
	result = ft_strjoin_no_spc(res, result);
	*i += size;
	free(tmp);
	return (result);
}

char	*repelse(int *i, const char *res, char *str)
{
	int		size;
	char	*result;

	size = countbefc(str + *i, "\'\"$");
	result = ft_strjoin_no_spc(res, ft_strdup2(str + *i, size));
	*i += size;
	return (result);
}
