/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   schottky.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 21:17:32 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/19 10:29:40 by mcanal           ###   ########.fr       */
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
	double complex	c;
	double complex	z;

	ratio = 2.7 / WIN_SIZE / e->zoom;
	i = -1;
	c = -1.25;
	while (j = -1, ++i < WIN_SIZE)
		while (++j < WIN_SIZE)
		{
			z = (i - e->x_base) * ratio + I * (j - e->y_base) * ratio;
			it = -1;
			while (++it < e->iter && (int)z < 2)
				z = z * z + c;
			if (it < e->iter)
				put_pixel_to_img(e, i, j, rgb(it, e->iter));
		}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
