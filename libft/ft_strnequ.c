/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeblonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 16:26:59 by jeblonde          #+#    #+#             */
/*   Updated: 2016/11/22 21:26:35 by jeblonde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (s1 && s2 && n)
	{
		while (i < n)
		{
			if (!s1[i] && !s2[i])
				return (1);
			if (s1[i] != s2[i] || !(s1[i] || s2[i]))
				return (0);
			i++;
		}
	}
	return (1);
}
