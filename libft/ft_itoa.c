/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeblonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 21:04:56 by jeblonde          #+#    #+#             */
/*   Updated: 2016/11/22 21:51:27 by jeblonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count(int nb)
{
	unsigned int	tmp;
	int				i;

	i = 0;
	tmp = nb;
	if (nb < 0)
	{
		i++;
		tmp = -nb;
	}
	while (tmp > 9)
	{
		tmp /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int nb)
{
	int				i;
	unsigned int	tmp;
	char			*dest;

	i = 0;
	i = count(nb);
	if (!(dest = ft_memalloc(i + 2)))
		return (NULL);
	dest[i + 1] = '\0';
	tmp = nb;
	if (nb < 0)
	{
		dest[0] = '-';
		tmp = -nb;
	}
	while (tmp > 9)
	{
		dest[i] = (tmp % 10) + 48;
		tmp /= 10;
		i--;
	}
	dest[i] = (tmp % 10) + 48;
	return (dest);
}
