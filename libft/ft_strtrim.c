/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeblonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:22:15 by jeblonde          #+#    #+#             */
/*   Updated: 2016/11/25 22:38:41 by jeblonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_start(char const *s)
{
	int		i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	start;
	char			*dest;

	j = 0;
	if (!(s))
		return (NULL);
	i = ft_start(s);
	start = i;
	if (i == ft_strlen(s))
		return (ft_strnew(1));
	while (s[i + j])
		j++;
	while (s[i + j - 1] == ' ' || s[i + j - 1] == '\t' || s[i + j - 1] == '\n')
		j--;
	i = 0;
	if (!(dest = ft_memalloc(j + 1)))
		return (NULL);
	while (j--)
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}
