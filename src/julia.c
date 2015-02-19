/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 20:53:20 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/19 21:59:02 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** julia fractal drawing!
*/

#include "header.h"

int				julia_move(int x, int y, t_env *e)
{
	if (!((x + y) % 2) && !e->lock)
	{
		e->ju = (C_DOUBLE)(x + y) / (C_DOUBLE)WIN_SIZE;
		ex_hook(e);
	}
	return (0);
}

void			julia(t_env *e, double ratio, t_char it)
{
	int				i;
	int				j;
	C_DOUBLE		z;

	ratio = e->zoom * WIN_SIZE / 2;
	i = -1;
	while (j = -1, ++i < WIN_SIZE)
		while (++j < WIN_SIZE)
		{
			z = (i - WIN_SIZE / 2 - e->x) / ratio +\
				I * (j - WIN_SIZE / 2 - e->y) / ratio;
			it = -1;
			while (++it < e->iter && (int)z < 2)
				z = z * z + e->ju;
			if (it == e->iter)
				put_pixel_to_img(e, i, j, e->color * (0 % 0xFF));
			else
				put_pixel_to_img(e, i, j, e->color * (it % 0xFF));
		}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
