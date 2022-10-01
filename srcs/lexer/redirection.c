/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:11:15 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/10/01 22:00:59 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	init_file(int fd, int i, t_parse *parse)
{
	if (i == 2)
	{
		if (parse->infile == 0)
			parse->infile = fd;
		else
		{
			close(parse->infile);
			parse->infile = fd;
		}
	}
	else
	{
		if (parse->outfile == 1)
			parse->outfile = fd;
		else
		{
			close(parse->outfile);
			parse->outfile = fd;
		}
	}
}

void	open_file(char *str, int i, t_parse *parse)
{
	int	file;

	file = 0;
	if (i == 0)
	{
		file = open(str, O_WRONLY | O_CREAT | O_APPEND, 0777);
	}
	else if (i == 1)
		file = open(str, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
	{
		file = open(str, O_RDONLY, 0777);
		if (file == -1)
			parse->infile = 0;
	}
	init_file(file, i, parse);
}

int	redirection_v(char *line, int i, t_parse *parse)
{
	int		j;

	j = i;
	if (line[i] == '>' && line[i + 1] == '>')
	{
		j += 2;
		parse->sfile = ft_expand(nextword(line + i + 2, &j));
		open_file(parse->sfile, 0, parse);
	}
	else if (line[i] == '>' && line[i + 1] != '>')
	{
		j++;
		parse->sfile = ft_expand(nextword(line + i + 1, &j));
		open_file(parse->sfile, 1, parse);
	}
	else
		j = redirection_v2(line, i, parse);
	return (j);
}

int	redirection_v2(char *line, int i, t_parse *parse)
{
	int		j;

	j = i;
	if (line[i] == '<' && line[i + 1] == '<')
	{
		j += 2;
		parse->sfile = nextword(line + i + 2, &j);
		g_global.here = 1;
		heredoc(parse->sfile, parse);
		g_global.here = 0;
	}
	else if (line[i] == '<' && line[i + 1] != '<')
	{
		j++;
		parse->sfile = nextword(line + i + 1, &j);
		parse->sfile = ft_expand(parse->sfile);
		open_file(parse->sfile, 2, parse);
	}
	return (j);
}
