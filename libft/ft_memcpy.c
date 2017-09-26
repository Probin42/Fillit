/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeblonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:22:44 by jeblonde          #+#    #+#             */
/*   Updated: 2016/11/21 21:04:49 by jeblonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dst;
	char	*sr;

	dst = ((char*)dest);
	sr = ((char*)src);
	if (dest != NULL || src != NULL)
	{
		while (n--)
			dst[n] = sr[n];
		return (dst);
	}
	return (NULL);
}
