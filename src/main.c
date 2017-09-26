/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeblonde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 10:35:19 by jeblonde          #+#    #+#             */
/*   Updated: 2017/01/12 15:39:52 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"
#include "../libft/libft.h"

int				main(int ac, char **av)
{
	t_corps	corps;

	if (ac != 2)
		ft_exit("usage: ./fillit extern_file");
	ft_bzero(&corps, sizeof(corps));
	get_pieces(&corps, av[1]);
	launcher(&corps);
	print_it(&corps);
	return (0);
}
