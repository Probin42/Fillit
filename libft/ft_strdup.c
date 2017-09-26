/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeblonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:11:43 by jeblonde          #+#    #+#             */
/*   Updated: 2016/11/21 21:00:51 by jeblonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned int	i;
	char			*dest;

	i = ft_strlen(s);
	if (!(dest = ft_strnew(i)))
		return (NULL);
	ft_strcpy(dest, s);
	return (dest);
}
