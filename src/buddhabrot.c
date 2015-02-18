/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 21:17:32 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/19 00:37:10 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** boudha :P
*/

#include "header.h"

static int		rgb(t_char i, t_char i_max)
{
	if (i % 2)
		return (i * 255 / i_max * 65536);
	else
		return (i * 255 / i_max * 256);
}

void			buddhabrot(t_env *e, double ratio, t_char it)
{
	int				i;
	int				j;
	double complex	c;
	double complex	z;
//	t_char			tab[WIN_SIZE][2];

	ratio = 2.7 / WIN_SIZE * e->zoom;
	i = -1;
	while (j = -1, ++i < WIN_SIZE)
		while (++j < WIN_SIZE)
		{
			z = (i - e->x_base) * ratio + I * (j - e->y_base) * ratio;
			c = -1.25;
			it = -1;
			while (++it < e->iter && (int)z < 2)
				z = z * z + c;
			if (it < e->iter)
				mlx_put_pixel_to_img(e, i, j, rgb(it, e->iter));
		}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
