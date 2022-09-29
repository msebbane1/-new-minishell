/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:30:32 by lbally            #+#    #+#             */
/*   Updated: 2022/09/28 17:47:28 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_ola(long int nb)
{
	if (nb < 0)
	{
		return (-nb);
	}
	return (nb);
}

int	ft_len(long int nb)
{
	int		len;

	len = (nb <= 0) ? 1 : 0;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*c;

	sign = (n < 0) ? -1 : 1;
	len = ft_len(n);
	c = (char *)malloc(sizeof(char) * len + 1);
	if (c == NULL)
		return (0);
	c[len] = '\0';
	len--;
	while (len >= 0)
	{
		c[len] = '0' + ft_ola(n % 10);
		n = ft_ola(n / 10);
		len--;
	}
	if (sign == -1)
		c[0] = '-';
	return (c);
}
