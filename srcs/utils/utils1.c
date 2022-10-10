/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:24:26 by lbally            #+#    #+#             */
/*   Updated: 2022/10/10 18:09:39 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*tolower2(char *cmd)
{
	int	i;

	i = 0;
	if (!cmd || cmd == NULL)
		return (NULL);
	while (cmd[i])
	{
		if (cmd[i] >= 'A' && cmd[i] <= 'Z')
			cmd[i] += 32;
		i++;
	}
	return (cmd);
}

int	ft_cmpchar(char s1, char s2)
{
	if (s1 != s2)
		return (1);
	else
		return (0);
}

int	back_slash(char *str)
{
	if (str[ft_strlen(str)] == '/')
		return (1);
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = -1;
	if ((!s1 || s1 == NULL) || (!s2 || s2 == NULL))
		return (-1);
	while (str1[++i] && str2[i])
	{
		if (str1[i] != str2[i])
			break ;
	}
	return (str1[i] - str2[i]);
}

int	len_envp(char **envp)
{
	int	i;

	i = 0;
	if (!envp)
		return (0);
	while (envp && envp[i] != '\0')
	{
		i++;
	}
	return (i);
}
