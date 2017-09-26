/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 12:23:59 by rweiss            #+#    #+#             */
/*   Updated: 2017/01/12 15:39:03 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <unistd.h>

static void		pieces_check(t_corps *corps)
{
	corps->sharp = 0;
	corps->x = -1;
	while (corps->tetri_tab[++corps->x] != NULL)
	{
		corps->y = -1;
		while (corps->tetri_tab[corps->x][++corps->y] != '\0')
			if (corps->tetri_tab[corps->x][corps->y] != '.' &&
					corps->tetri_tab[corps->x][corps->y] != '#')
				ft_exit("error");
			else if (corps->tetri_tab[corps->x][corps->y] == '#')
				corps->sharp++;
		if (corps->y != 4)
			ft_exit("error");
	}
	if (corps->x % 4 != 0 || corps->x == 0)
		ft_exit("error");
	corps->nb = corps->x / 4;
	if (corps->nb > 26 || corps->nb < 0 || corps->sharp % corps->nb != 0)
		ft_exit("error");
	if (corps->nb == 0)
		ft_exit(NULL);
	corps->width = corps->nb * 4 + 1;
	corps->good_width = corps->width;
}

static void		pieces_check_again(t_corps *corps)
{
	int		j;
	int		i;

	j = 0;
	corps->x = 0;
	corps->y = -1;
	while (corps->tetri_tab[corps->x] != NULL)
	{
		i = -1;
		while (++i < 16)
		{
			if (corps->tetri_tab[corps->x][++corps->y] == '#')
				j++;
			if (((i + 1) % 4) == 0)
			{
				corps->x++;
				corps->y = -1;
			}
		}
		if (j == 0 || (j % 4) != 0)
			ft_exit("error");
	}
}

static void		seek_for_first_sharp(t_tetrim *tetrim)
{
	tetrim->y_start = 0;
	tetrim->x_start = 0;
	while (tetrim->substance[tetrim->y_start][tetrim->x_start] != '#')
	{
		if (tetrim->x_start == 4)
		{
			tetrim->x_start = 0;
			tetrim->y_start++;
		}
		tetrim->x_start++;
	}
}

static void		convert_tab(t_corps *corps)
{
	int		i;

	if (!(corps->tetrim = (t_tetrim**)ft_memalloc(sizeof(t_tetrim*)
					* corps->nb)))
		ft_exit("error");
	i = -1;
	while (++i < corps->nb)
	{
		if (!(corps->tetrim[i] = (t_tetrim*)ft_memalloc(sizeof(t_tetrim)))
		|| !(corps->tetrim[i]->substance =
			(char**)ft_memalloc(sizeof(char*) * 4))
		|| !(corps->tetrim[i]->substance[0] =
			ft_strsub(corps->tetri_tab[i * 4], 0, 4))
		|| !(corps->tetrim[i]->substance[1] =
			ft_strsub(corps->tetri_tab[i * 4 + 1], 0, 4))
		|| !(corps->tetrim[i]->substance[2] =
			ft_strsub(corps->tetri_tab[i * 4 + 2], 0, 4))
		|| !(corps->tetrim[i]->substance[3] =
			ft_strsub(corps->tetri_tab[i * 4 + 3], 0, 4)))
			ft_exit("error");
		corps->tetrim[i]->x = 0;
		corps->tetrim[i]->y = 0;
		seek_for_first_sharp(corps->tetrim[i]);
	}
}

void			get_pieces(t_corps *corps, char *filename)
{
	int		i;

	check_for_errors(corps, filename);
	pieces_check(corps);
	pieces_check_again(corps);
	convert_tab(corps);
	check_tetri_contain(corps);
	i = -1;
	while (++i < corps->nb - 1)
	{
		if (corps->buff[((i + 1) * 20 + i - 1)] != '\n'
		|| corps->buff[((i + 1) * 20 + i)] != '\n')
			ft_exit("error");
	}
}
