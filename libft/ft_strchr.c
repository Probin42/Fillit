/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeblonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 19:39:40 by jeblonde          #+#    #+#             */
/*   Updated: 2016/11/21 21:01:44 by jeblonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			is;
	char			*dest;

	dest = ((char*)s);
	is = ((char)c);
	i = ft_strlen(s);
	while (i)
	{
		if (*dest == is)
			return (dest);
		dest++;
		i--;
	}
	if (is == '\0')
		return (dest);
	return (NULL);
}
