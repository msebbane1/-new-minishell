/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repquotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:11:27 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/10/01 22:07:50 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*repquotes(int *i, const char *res, char *str)
{
	int		size;
	char	*result;
	char	*tmp;

	size = countbefc(str, "\'");
	if (size == 0)
	{
		*i += 1;
		return ((char *)res);
	}
	tmp = ft_strdup2(str, size);
	result = ft_strjoin_no_spc(res, tmp);
	*i += size + 1;
	return (result);
}

char	*repdblquotes(int *i, const char *res, char *str)
{
	int		size;
	char	*result;

	size = countbefc(str, "\"$");
	if (size == 0)
		return ((char *)res);
	result = ft_strjoin_no_spc(res, ft_strdup2(str, size));
	*i += size - 1;
	while (str[*i] != '\"' && str[*i])
	{
		if (str[*i] == '$')
		{
			*i += 1;
			result = repdollar(i, result, str + *i);
		}
		else
		{
			size = countbefc(str + *i, "\"$");
			result = ft_strjoin_no_spc(result, ft_strdup2(str + *i, size));
			*i += size;
		}
	}
	*i += 1;
	return (result);
}

char	*repdollar(int *i, const char *res, char *str)
{
	int		size;
	char	*result;
	char	*tmp;

	if (str[0] == '?')
	{
		*i += 1;
		tmp = ft_strjoin_no_spc(res, ft_itoa(g_global.status));
		return (tmp);
	}
	if (str[0] == '\0')
	{
		*i += 1;
		tmp = ft_strjoin_no_spc(res, ft_strdup("$"));
		return (tmp);
	}
	size = countbefc(str, "\'\"$ ");
	if (size == 0)
		return ((char *)res);
	tmp = ft_strdup2(str, size);
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

	size = countbefc(str, "\'\"$");
	result = ft_strjoin_no_spc(res, ft_strdup2(str, size));
	*i += size;
	return (result);
}
