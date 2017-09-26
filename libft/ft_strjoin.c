/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeblonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:56:27 by jeblonde          #+#    #+#             */
/*   Updated: 2016/11/23 21:03:39 by jeblonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (s1 && s2)
	{
		i = ft_strlen(s1);
		if (!(dest = (char*)malloc(sizeof(char) * (i + ft_strlen(s2) + 1))))
			return (NULL);
		while (j < i)
		{
			dest[j] = s1[j];
			j++;
		}
		while (s2[j - i])
		{
			dest[j] = s2[j - i];
			j++;
		}
		dest[j] = '\0';
		return (dest);
	}
	return (NULL);
}
