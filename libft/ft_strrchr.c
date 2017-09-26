/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeblonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 19:57:52 by jeblonde          #+#    #+#             */
/*   Updated: 2016/11/22 22:05:18 by jeblonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	is;
	char	*dest;
	int		i;

	i = ft_strlen(s);
	is = ((char)c);
	dest = ((char*)s);
	while (dest[i] != is && i >= 0)
		i--;
	if (dest[i] == is)
		return ((char*)&s[i]);
	return (NULL);
}
