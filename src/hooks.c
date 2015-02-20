/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 17:28:24 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/20 17:23:50 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** hooks et plus si affinité
*/

#include "header.h"

int			ex_hook(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img);
	if (!(e->img = mlx_new_image(e->mlx, WIN_SIZE, WIN_SIZE)))
		error(IMG_PTR);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->x_len), &(e->endian));
	if (e->fractal == 'M')
		mandelbrot(e, 0);
	else if (e->fractal == 'J')
		julia(e, 0);
	else if (e->fractal == 'S')
		schottky(e, 0);
	else if (e->fractal == 'C')
		chromosom(e, 0);
	else if (e->fractal == 'N')
		noun(e, 0);
	else if (e->fractal == 'D')
		rabbit(e, 0);
	return (0);
}

static void	another_key_hook(int key, t_env *e)
{
	if (key == ESC)
		ft_putstr_clr("K_THX_BYE", "b"), kill(0, SIGINT);
	else if (key == ONE)
		e->color += 0x100000, ex_hook(e);
	else if (key == TWO)
		e->color += 0x001000, ex_hook(e);
	else if (key == THREE)
		e->color += 0x000010, ex_hook(e);
	else if (key == FOUR)
		e->color -= 0x100000, ex_hook(e);
	else if (key == FIVE)
		e->color -= 0x001000, ex_hook(e);
	else if (key == SIX)
		e->color -= 0x000010, ex_hook(e);
	else if (key == ENTER)
		e->lock = e->lock == 0 ? 1 : 0;
}

int			key_hook(int key, t_env *e)
{
	if (key == PAGE_UP)
		e->iter += e->iter == 253 ? 2 : 3;
	else if (key == PAGE_DOWN)
		e->iter -= e->iter == 3 ? 2 : 3;
	else if (key == UP || key == DOWN)
		e->y += key == UP ? 10 : -10, ex_hook(e);
	else if (key == LEFT || key == RIGHT)
		e->x += key == LEFT ? 10 : -10, ex_hook(e);
	else if (key == SPACE)
	{
		e->x = WIN_SIZE / 2;
		e->y = WIN_SIZE / 2;
		e->zoom = WIN_SIZE / 2;
		e->iter = 49;
		e->color = 0x3F0000;
		ex_hook(e);
	}
	else if (key == L_CTRL)
		disco(e, 60);
	else if ((key >= ONE && key <= SIX) || key == ENTER)
		another_key_hook(key, e);
	if (key == PAGE_UP || key == PAGE_DOWN)
		ft_debugnbr("IterationLevel", e->iter), ex_hook(e);
	return (0);
}

int			mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == SCROLL_UP || button == LEFT_CLICK)
	{
		e->x += (WIN_SIZE / 2) - x;
		e->y += (WIN_SIZE / 2) - y;
		e->zoom /= 0.99;
		ft_debugnbr("e->x", e->x);
		ft_debugnbr("e->y", e->y);
		ft_debugnbr("x", x);
		ft_debugnbr("y", y);
	}
	else if (button == SCROLL_DOWN || button == RIGHT_CLICK)
		e->zoom *= 0.99;
	if (button == SCROLL_UP || button == SCROLL_DOWN || \
		button == LEFT_CLICK || button == RIGHT_CLICK)
		ex_hook(e);
	return (0);
}

int			mouse_move(int x, int y, t_env *e)
{
	if ((x + y) % 10 < 6 && !e->lock)
	{
		if ((x + y) % 3 == 1)
			e->color += 0x100000;
		else if ((x + y) % 3 == 2)
			e->color += 0x000010;
		else
			e->color += 0x001000;
		ex_hook(e);
	}
	return (0);
}
