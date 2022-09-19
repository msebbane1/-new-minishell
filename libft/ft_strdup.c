/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:35:57 by lbally            #+#    #+#             */
/*   Updated: 2022/09/19 17:31:20 by lbally           ###   ########.fr       */
=======
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:35:57 by lbally            #+#    #+#             */
/*   Updated: 2022/09/19 20:15:27 by vl-hotel         ###   ########.fr       */
>>>>>>> dcf2f8051de5c3989ff3757fb82f3d997f88d938
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*new;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	new = malloc(sizeof(char) * i + 1);
	if (!new)
		return (0);
	i = 0;
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
