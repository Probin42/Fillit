/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 12:22:57 by rweiss            #+#    #+#             */
/*   Updated: 2017/01/12 15:43:42 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define FD corps->fd
# define VREAD corps->vread
# define BUFF corps->buff
# define BUFF_SIZE 546
# define Y(i) corps->tetrim[i]->y
# define YSTART(i) corps->tetrim[i]->y_start
# define X(i) corps->tetrim[i]->x
# define XSTART(i) corps->tetrim[i]->x_start

typedef struct		s_tetrim
{
	char			**substance;
	int				x;
	int				y;
	int				x_start;
	int				y_start;
}					t_tetrim;

typedef struct		s_corps
{
	char			**tetri_tab;
	int				nb;
	int				next;
	int				vread;
	int				sharp;
	char			buff[BUFF_SIZE + 1];
	int				x;
	int				y;
	int				a;
	int				b;
	char			**map;
	int				lenght;
	int				good_map;
	int				width;
	int				good_width;
	t_tetrim		**tetrim;
	t_tetrim		**good_tetrim;
}					t_corps;

void				modify_body(t_corps *corps, int nb, char c);
void				del_tetri_in_map(t_corps *env, int nb_tetri);
int					puttomap(t_corps *corps, int nb);
void				good_map(t_corps *corps);
void				launcher(t_corps *corps);
void				print_it(t_corps *corps);
void				exchange_tetrim(t_corps *corps, int nb, char c);
void				check_for_errors(t_corps *corps, char *filename);
void				get_pieces(t_corps *corps, char *filename);
void				check_tetri_contain(t_corps *corps);
void				verify_tetri(t_corps *corps, int i, int nbc, int nbl);
void				ft_exit(char *message);
#endif
