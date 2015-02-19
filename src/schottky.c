/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   schottky.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 21:17:32 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/19 21:53:17 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** boudha :P
*/

#include "header.h"

void			schottky(t_env *e, double ratio, t_char it)
{
	int				i;
	int				j;
	C_DOUBLE		c;
	C_DOUBLE		z;

	ratio = e->zoom * WIN_SIZE / 2;
	i = -1;
	c = -1.25;
	while (j = -1, ++i < WIN_SIZE)
		while (++j < WIN_SIZE)
		{
			z = (i - WIN_SIZE / 2 - e->x) / ratio + \
				I * (j - WIN_SIZE / 2 - e->y) / ratio;
			it = -1;
			while (++it < e->iter && (int)z < 2)
				z = z * z + c;
			if (it == e->iter)
				put_pixel_to_img(e, i, j, e->color * (0 % 0xFF));
			else
				put_pixel_to_img(e, i, j, e->color * (it % 0xFF));
		}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
