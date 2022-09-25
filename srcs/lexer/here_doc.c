/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 20:52:44 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/09/25 20:53:45 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	heredoc(char *stop, t_parse *parse)
{
	char	*line;
	int		file;

	file = open("/tmp/heredoc.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file < 0)
		printf("probleme avec le here doc\n");
	g_global.parse->fd_kill = file;
	line = NULL;
	while (1)
	{
		line = readline("here_doc >>");
		if (ft_strncmp(line, stop, ft_strlen(stop)) == 0
			&& (ft_strlen(stop) == ft_strlen(line)))
		{
			free(line);
			break ;
		}
		write(file, line, ft_strlen(line));
		write(file, "\n", 1);
		free(line);
	}
	init_file(file, 2, parse);
}
