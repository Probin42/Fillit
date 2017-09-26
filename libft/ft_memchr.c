/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeblonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 21:07:30 by jeblonde          #+#    #+#             */
/*   Updated: 2016/11/21 21:07:46 by jeblonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	is;

	dest = ((unsigned char*)s);
	is = ((unsigned char)c);
	while (n--)
	{
		if (*dest == is)
			return (dest);
		dest++;
	}
	return (NULL);
}
