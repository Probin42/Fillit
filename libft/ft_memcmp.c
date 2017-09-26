/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeblonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 21:54:49 by jeblonde          #+#    #+#             */
/*   Updated: 2016/11/25 22:27:38 by jeblonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*si1;
	unsigned char	*si2;
	unsigned int	i;

	i = 0;
	si1 = ((unsigned char*)s1);
	si2 = ((unsigned char*)s2);
	while (n)
	{
		if (si1[i] != si2[i])
			return (si1[i] - si2[i]);
		i++;
		n--;
	}
	return (0);
}
