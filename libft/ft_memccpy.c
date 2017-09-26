/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeblonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:43:39 by jeblonde          #+#    #+#             */
/*   Updated: 2016/11/21 21:07:12 by jeblonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*sr;
	unsigned char	*destc;

	destc = ((unsigned char*)dest);
	sr = ((unsigned char*)src);
	if (destc != NULL || sr != NULL)
	{
		while (n--)
		{
			*destc = *sr;
			if (*destc == ((unsigned char)c))
				return ((void *)destc + 1);
			destc++;
			sr++;
		}
	}
	return (NULL);
}
