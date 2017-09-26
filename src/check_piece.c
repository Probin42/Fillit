/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 12:23:43 by rweiss            #+#    #+#             */
/*   Updated: 2017/01/12 15:38:02 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"
#include "../libft/libft.h"

static int		lines_contain_sharp(t_corps *corps, int tetri)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (corps->tetrim[tetri]->substance[i][j] == '#')
			{
				count++;
				break ;
			}
		}
	}
	return (count);
}

static int		columns_contain_sharp(t_corps *corps, int tetri)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (corps->tetrim[tetri]->substance[j][i] == '#')
			{
				count++;
				break ;
			}
		}
	}
	return (count);
}

static void		check_lines_n_columns(t_corps *corps, int i)
{
	const int		nb_lines = lines_contain_sharp(corps, i);
	const int		nb_col = columns_contain_sharp(corps, i);

	if ((nb_lines == 1 && nb_col != 4)
	|| (nb_lines == 2 && nb_col != 2 && nb_col != 3)
	|| (nb_lines == 3 && nb_col != 2)
	|| (nb_lines == 4 && nb_col != 1))
		ft_exit("error");
	verify_tetri(corps, i, nb_col, nb_lines);
}

static void		check_tetri_location(t_corps *corps, int i, int *count)
{
	if (*count < 4 && ((corps->x < 3 &&
	corps->tetrim[i]->substance[corps->y][corps->x + 1] == '#') || (corps->x > \
		0 && corps->tetrim[i]->substance[corps->y][corps->x - 1] == '#')
	|| (corps->y < 3 &&
		corps->tetrim[i]->substance[corps->y + 1][corps->x] == '#')
	|| (corps->y > 0 &&
		corps->tetrim[i]->substance[corps->y - 1][corps->x] == '#')))
		*count = *count + 1;
	else
		ft_exit("error");
	check_lines_n_columns(corps, i);
}

void			check_tetri_contain(t_corps *corps)
{
	int		i;
	int		count;

	i = -1;
	while (++i < corps->nb)
	{
		count = 0;
		corps->y = -1;
		while (++corps->y < 4)
		{
			corps->x = -1;
			while (++corps->x < 4)
				if (corps->tetrim[i]->substance[corps->y][corps->x] == '#')
					check_tetri_location(corps, i, &count);
		}
	}
}
