/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeblonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 16:38:26 by jeblonde          #+#    #+#             */
/*   Updated: 2016/11/13 15:30:58 by jeblonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s && f)
	{
		while (s[i])
			i++;
		if (!(dest = (char*)malloc(sizeof(char) * (i + 1))))
			return (NULL);
		dest[i] = '\0';
		while (j < i)
		{
			dest[j] = f(s[j]);
			j++;
		}
		return (dest);
	}
	return (NULL);
}
