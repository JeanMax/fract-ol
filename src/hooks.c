/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 17:28:24 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/17 01:21:03 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** hooks et plus si affinité
*/

#include "header.h"

int		ex_hook(t_env *e)
{
	mlx_clear_window(e->mlx, e->win); //bjorked :/
	mandelbrot(e);
	return (0);
}

int		key_hook(int key, t_env *e)
{
	if (key == ESC)
		ft_putendl_clr("K_THX_BYE", "b"), exit(0);
	else if (key == NUM_PLUS && e->iter != 100)
		e->iter += 3;
	else if (key == NUM_MINUS && e->iter != 1)
		e->iter -= 3;
	else if (key == UP)
		e->y_base -= 5;
	else if (key == DOWN)
		e->y_base += 5;
	else if (key == LEFT)
		e->x_base -= 5;
	else if (key == RIGHT)
		e->x_base += 5;
	else
		ft_debugnbr("key", key); //debug
	if (key == NUM_PLUS || key == NUM_MINUS)
		ft_debugnbr("IterationLevel", e->iter), ex_hook(e);
	else if (key >= LEFT && key <= DOWN)
		ft_debugnbr("x", e->x_base), ft_debugnbr("y", e->y_base), ex_hook(e);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	e = e; //debug
	ft_debugnbr("button", button); //debug
	ft_debugnbr("x", x); //debug
	ft_debugnbr("y", y); //debug
	return (0);
}
