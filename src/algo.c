/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 12:23:34 by rweiss            #+#    #+#             */
/*   Updated: 2017/01/12 15:36:42 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"
#include "../libft/libft.h"

static int		value_start(t_corps *corps)
{
	int		n;
	float	r;
	float	s;
	int		i;

	n = (corps->nb) ? corps->nb : 1;
	r = 1;
	i = 0;
	while (++i <= n)
		r = 0.5 * (r + n / r);
	s = r - (int)r;
	return ((s > 0) ? (int)r + 1 : r);
}

static void		validate_init(t_corps *corps)
{
	int			i;

	corps->map = (char**)ft_memalloc(sizeof(char*) * corps->width);
	i = -1;
	while (++i < corps->width)
		corps->map[i] = (char*)ft_strnew(corps->width);
	corps->lenght = 4242;
	corps->good_map = 4242;
	corps->width = value_start(corps);
}

static void		begin_initialisation(t_corps *corps)
{
	int i;

	if (!(corps->good_tetrim = (t_tetrim**)ft_memalloc(sizeof(t_tetrim*)
					* corps->nb)))
		ft_exit("error");
	i = -1;
	while (++i < corps->nb)
	{
		if (!(corps->good_tetrim[i] = (t_tetrim*)ft_memalloc(sizeof(t_tetrim)))
		|| !(corps->good_tetrim[i]->substance =
		(char**)ft_memalloc(sizeof(char*) * 4))
		|| !(corps->good_tetrim[i]->substance[0] =
		ft_strsub(corps->tetri_tab[i * 4], 0, 4))
		|| !(corps->good_tetrim[i]->substance[1] =
		ft_strsub(corps->tetri_tab[i * 4 + 1], 0, 4))
		|| !(corps->good_tetrim[i]->substance[2] =
		ft_strsub(corps->tetri_tab[i * 4 + 2], 0, 4))
		|| !(corps->good_tetrim[i]->substance[3] =
		ft_strsub(corps->tetri_tab[i * 4 + 3], 0, 4)))
			ft_exit("error");
		corps->good_tetrim[i]->x = 0;
		corps->good_tetrim[i]->y = 0;
	}
	validate_init(corps);
}

static void		algo_baby(t_corps *corps, int obj)
{
	corps->tetrim[obj]->y = -1;
	while (corps->good_map == 4242 && ++corps->tetrim[obj]->y < corps->width)
	{
		corps->tetrim[obj]->x = -1;
		while (corps->good_map == 4242 && ++corps->tetrim[obj]->x <
				corps->width)
		{
			if (puttomap(corps, obj))
				continue ;
			if (obj + 1 == corps->nb)
			{
				good_map(corps);
				return ;
			}
			else
				algo_baby(corps, obj + 1);
			exchange_tetrim(corps, obj, 0);
		}
	}
}

void			launcher(t_corps *corps)
{
	begin_initialisation(corps);
	while (++corps->width < corps->good_width && corps->good_map == 4242)
	{
		algo_baby(corps, 0);
	}
}
