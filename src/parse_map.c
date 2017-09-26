/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 12:24:27 by rweiss            #+#    #+#             */
/*   Updated: 2017/01/12 15:41:40 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"
#include "../libft/libft.h"

static void		convert_tetrim(t_corps *corps)
{
	int		i;

	i = -1;
	while (++i < corps->nb)
	{
		corps->tetrim[i]->x = corps->good_tetrim[i]->x;
		corps->tetrim[i]->y = corps->good_tetrim[i]->y;
		ft_memcpy(corps->tetrim[i]->substance[0], \
				corps->good_tetrim[i]->substance[0], 5);
		ft_memcpy(corps->tetrim[i]->substance[1], \
				corps->good_tetrim[i]->substance[1], 5);
		ft_memcpy(corps->tetrim[i]->substance[2], \
				corps->good_tetrim[i]->substance[2], 5);
		ft_memcpy(corps->tetrim[i]->substance[3], \
				corps->good_tetrim[i]->substance[3], 5);
	}
	corps->lenght = corps->good_map;
}

static void		empty_it(t_corps *corps)
{
	int		i;

	i = -1;
	while (++i < corps->width)
		ft_bzero(corps->map[i], corps->width);
}

static void		fill_it(t_corps *corps)
{
	int		i;
	int		j;

	i = -1;
	while (++i < corps->nb)
		puttomap(corps, i);
	i = -1;
	while (++i < corps->lenght)
	{
		j = -1;
		while (++j < corps->lenght)
		{
			if (corps->map[i][j])
				corps->map[i][j] += 17;
			else
				corps->map[i][j] = '.';
		}
	}
}

void			print_it(t_corps *corps)
{
	int		i;
	int		j;

	convert_tetrim(corps);
	empty_it(corps);
	fill_it(corps);
	i = -1;
	while (++i < corps->lenght)
	{
		j = -1;
		while (++j < corps->lenght)
			ft_putchar((corps->map[i][j]) ? corps->map[i][j] : '.');
		ft_putchar('\n');
	}
}
