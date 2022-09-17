/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:35:02 by lbally            #+#    #+#             */
/*   Updated: 2022/07/22 12:35:03 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	numb;
	int				a;

	if (n < 0)
	{
		write(fd, "-", 1);
		numb = -n;
	}
	else
		numb = n;
	a = ('0' + (numb % 10));
	numb = numb / 10;
	if (numb > 0)
		ft_putnbr_fd(numb, fd);
	write(fd, &a, 1);
}
