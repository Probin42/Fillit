/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeblonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 15:35:02 by jeblonde          #+#    #+#             */
/*   Updated: 2016/11/25 22:30:56 by jeblonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	i;

	i = 0;
	if (s)
	{
		if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (len)
		{
			dest[i] = s[start];
			i++;
			start++;
			len--;
		}
		dest[i] = '\0';
		return (dest);
	}
	return (NULL);
}
