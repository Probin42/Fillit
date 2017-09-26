/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeblonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 11:26:50 by jeblonde          #+#    #+#             */
/*   Updated: 2017/01/12 15:40:55 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"
#include "../libft/libft.h"

static int	size_map(t_corps *corps)
{
	int		i;
	int		j;
	int		s;
	int		t_max;

	s = 0;
	i = -1;
	while (++i < corps->width)
	{
		j = -1;
		while (++j < corps->width)
			if (corps->map[i][j] != 0 && (t_max = ft_max(i + 1, j + 1)) > s)
				s = t_max;
	}
	return (s);
}

static int	puttomap_reverse(t_corps *corps, int nb)
{
	exchange_tetrim(corps, nb, 0);
	return (-1);
}

int			puttomap(t_corps *corps, int nb)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (corps->tetrim[nb]->substance[i][j] != '#')
				continue;
			if (Y(nb) + i - YSTART(nb) < 0
			|| Y(nb) + i - YSTART(nb) >= corps->width
			|| X(nb) + j - XSTART(nb) < 0
			|| X(nb) + j - XSTART(nb) >= corps->width
			|| corps->map[Y(nb) + i - YSTART(nb)][X(nb) + j - XSTART(nb)] != 0)
				return (puttomap_reverse(corps, nb));
			corps->map[Y(nb) + i - YSTART(nb)][X(nb) + j - \
			XSTART(nb)] = nb + '0';
		}
	}
	corps->lenght = size_map(corps);
	return (0);
}

void		exchange_tetrim(t_corps *corps, int nb, char c)
{
	int		i;
	int		j;

	nb += '0';
	i = -1;
	while (++i < corps->width)
	{
		j = -1;
		while (++j < corps->width)
			if (corps->map[i][j] == nb)
				corps->map[i][j] = c;
	}
}

void		good_map(t_corps *corps)
{
	int		i;

	i = -1;
	while (++i < corps->nb)
	{
		corps->good_tetrim[i]->x = corps->tetrim[i]->x;
		corps->good_tetrim[i]->y = corps->tetrim[i]->y;
		ft_memcpy(corps->good_tetrim[i]->substance[0], \
				corps->tetrim[i]->substance[0], 5);
		ft_memcpy(corps->good_tetrim[i]->substance[1], \
				corps->tetrim[i]->substance[1], 5);
		ft_memcpy(corps->good_tetrim[i]->substance[2], \
				corps->tetrim[i]->substance[2], 5);
		ft_memcpy(corps->good_tetrim[i]->substance[3], \
				corps->tetrim[i]->substance[3], 5);
	}
	corps->good_map = corps->lenght;
}
