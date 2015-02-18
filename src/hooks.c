/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 17:28:24 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/19 00:33:13 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** hooks et plus si affinité
*/

#include "header.h"

int		ex_hook(t_env *e)
{
//	mlx_destroy_image(e->mlx, e->img);
	if (!(e->img = mlx_new_image(e->mlx, WIN_SIZE, WIN_SIZE)))
		error(IMG_PTR);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->x_len), &(e->endian));
	if (e->fractal == 'M')
		mandelbrot(e, 0, 0);
	else if (e->fractal == 'J')
		julia(e, 0, 0);
	else if (e->fractal == 'B')
		buddhabrot(e, 0, 0);
/* TODO:
	else if (e->fractal == 'T')
		tob(e);
*/
	return (0);
}

int		key_hook(int key, t_env *e)
{
	if (key == ESC)
	{
		ft_putendl_clr("K_THX_BYE", "b");
		mlx_destroy_window(e->mlx, e->win); //optional
		kill(0, SIGINT);
	}
	else if (key == PAGE_UP && e->iter < 100)
		e->iter += 3;
	else if (key == PAGE_DOWN && e->iter != 3)
		e->iter -= 3;
	else if (key == UP)
		e->y_base -= 10;
	else if (key == DOWN)
		e->y_base += 10;
	else if (key == LEFT)
		e->x_base -= 10;
	else if (key == RIGHT)
		e->x_base += 10;
	else if (key == NUM_PLUS)
		e->zoom *= 0.9;
	else if (key == NUM_MINUS)
		e->zoom /= 0.9;
	else if (key == SPACE)
	{
		e->x_base = WIN_SIZE * 0.5;
		e->y_base = WIN_SIZE * 0.5;
		e->zoom = 1;
		e->iter = 49;
		ex_hook(e);
	}
	else if (key == ENTER)
		e->lock += e->lock == 0 ? 1 : -1;
	else
		ft_debugnbr("key", key); //debug
	if (key == PAGE_UP || key == PAGE_DOWN)
		ft_debugnbr("IterationLevel", e->iter), ex_hook(e);
	else if (key >= LEFT && key <= DOWN)
		ft_debugnbr("x", e->x_base), ft_debugnbr("y", e->y_base), ex_hook(e);
	else if (key == NUM_PLUS || key == NUM_MINUS)
		ft_debugdbl("zoom", e->zoom), ex_hook(e);;
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == SCROLL_UP)
	{
		e->zoom *= 0.9;
		e->x_base += ((WIN_SIZE / 2) - x) / (e->zoom * 10);
		e->y_base += ((WIN_SIZE / 2) - y) / (e->zoom * 10);
	}
	else if (button == SCROLL_DOWN)
	{
		e->zoom /= 0.9;
//		e->x_base += ((WIN_SIZE / 2) - x) / (e->zoom * 10);
//		e->y_base += ((WIN_SIZE / 2) - y) / (e->zoom * 10);
	}
	else
		ft_debugnbr("button", button), ft_debugnbr("x", x), ft_debugnbr("y", y); //debug
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		ft_debugdbl("zoom", e->zoom), ex_hook(e);
	return (0);
}

int		mouse_move(int x, int y, t_env *e)
{
	if (!((x + y) % 10) && !e->lock)
	{
		e->iter = ((x + y) / 8 ) + 1;
		ft_debugnbr("IterationLevel", e->iter), ex_hook(e);
	}
	return (0);
}
