/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 18:09:34 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/17 22:51:05 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the main!;D
*/

#include "header.h"

static void		check_flag(int ac, char **av)
{
	if (ac != 2 || av[1][0] != '-')
		failn(USAGE), exit(-1);
	else if (av[1][1] == 'M')
		return ; //TODO
}

int				main(int ac, char **av)
{
	t_env		e;

	check_flag(ac, av);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_SIZE, WIN_SIZE, "zboub");
	e.iter = 49;
	e.zoom = 1;
	e.x_base = WIN_SIZE * 0.5;
	e.y_base = WIN_SIZE * 0.5;
	e.x_centre = 0;
	e.y_centre = 0;
	mlx_expose_hook(e.win, ex_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	if (!(e.img = mlx_new_image(e.mlx, WIN_SIZE, WIN_SIZE)))
	{
		failn("Error while creating img_ptr");
		return (0);
	}
	e.data = mlx_get_data_addr(e.img, &(e.bpp), &(e.size_line), &(e.endian));
	mlx_loop(e.mlx);
	return (0);
}
