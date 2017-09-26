/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeblonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 16:51:25 by jeblonde          #+#    #+#             */
/*   Updated: 2016/11/14 16:36:37 by jeblonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dest;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (s && f)
	{
		while (s[i])
			i++;
		if (!(dest = (char*)malloc(sizeof(char) * (i + 1))))
			return (NULL);
		dest[i] = '\0';
		while (j < i)
		{
			dest[j] = f(j, s[j]);
			j++;
		}
		return (dest);
	}
	return (NULL);
}
