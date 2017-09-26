/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeblonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 13:39:38 by jeblonde          #+#    #+#             */
/*   Updated: 2016/11/17 15:05:57 by jeblonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char			*dest;
	unsigned int	i;

	i = 0;
	dest = ((char*)s);
	while (i < n)
	{
		dest[i] = c;
		i++;
	}
	return (dest);
}
