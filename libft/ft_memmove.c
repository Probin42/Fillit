/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeblonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 21:02:29 by jeblonde          #+#    #+#             */
/*   Updated: 2016/11/23 01:16:05 by jeblonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (s1 <= s2)
		while (n > i)
		{
			((unsigned char*)s1)[i] = ((unsigned char*)s2)[i];
			i++;
		}
	else
		ft_memcpy(s1, s2, n);
	return (s1);
}
