/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yes_we_can.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 12:24:39 by rweiss            #+#    #+#             */
/*   Updated: 2017/01/12 15:42:35 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <fcntl.h>

static void		tabs_prep(int *lines, int *columns)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		lines[i] = 0;
		columns[i] = 0;
	}
}

static void		write_on_tabs(t_corps *corps, int tetri, int *l, int *c)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (corps->tetrim[tetri]->substance[i][j] == '#')
			{
				c[j] = 1;
				l[i] = 1;
			}
		}
	}
}

static int		search_first_tetri(int *tab)
{
	if (tab[0])
		return (0);
	if (tab[1])
		return (1);
	if (tab[2])
		return (2);
	return (3);
}

void			verify_tetri(t_corps *corps, int i, int nbc, int nbl)
{
	int		lines[4];
	int		columns[4];
	int		first;

	tabs_prep(&lines[0], &columns[0]);
	write_on_tabs(corps, i, &lines[0], &columns[0]);
	first = search_first_tetri(&columns[0]);
	if (nbc == 2 && (first > 2 || !columns[first + 1]))
		ft_exit("error");
	if (nbc == 3 && (first > 1 || !columns[first + 1] ||\
	!columns[first + 2]))
		ft_exit("error");
	first = search_first_tetri(&lines[0]);
	if (nbl == 2 && (first > 2 || !lines[first + 1]))
		ft_exit("error");
	if (nbl == 3 && (first > 1 || !lines[first + 1] || !lines[first + 2]))
		ft_exit("error");
}

void			check_for_errors(t_corps *corps, char *filename)
{
	if ((corps->next = open(filename, O_RDONLY)) == -1)
		ft_exit("error");
	if ((corps->vread = read(corps->next, corps->buff, BUFF_SIZE)) == -1
	|| corps->vread == 546)
		ft_exit("error");
	if ((close(corps->next)) == -1)
		ft_exit("error");
	if (((corps->vread + 1) % 21) != 0 ||
			ft_strstr(corps->buff, "\n\n\n") != NULL)
		ft_exit("error");
	if ((corps->tetri_tab = ft_strsplit(corps->buff, '\n')) == NULL)
		ft_exit("error");
}
