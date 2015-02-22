/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 17:28:24 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/22 13:22:49 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** hooks et plus si affinité
*/

#include "header.h"

static void	another_key_hook(int key, t_env *e)
{
	if (key == ESC)
		ft_putstr_clr("K_THX_BYE", "b"), kill(0, SIGINT);
	else if (key == ONE)
		e->color += 0x010000, e->hooking = 42;
	else if (key == TWO)
		e->color += 0x000100, e->hooking = 42;
	else if (key == THREE)
		e->color += 0x000001, e->hooking = 42;
	else if (key == FOUR)
		e->color -= 0x010000, e->hooking = 42;
	else if (key == FIVE)
		e->color -= 0x000100, e->hooking = 42;
	else if (key == SIX)
		e->color -= 0x000001, e->hooking = 42;
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
		e->y += key == UP ? 10 : -10, e->hooking = 42;
	else if (key == LEFT || key == RIGHT)
		e->x += key == LEFT ? 10 : -10, e->hooking = 42;
	else if (key == SPACE)
	{
		e->x = WIN_SIZE / 2;
		e->y = WIN_SIZE / 2;
		e->zoom = WIN_SIZE / 2;
		e->iter = 49;
		e->color = 0x010000;
		e->hooking = 42;
	}
	else if (key == L_CTRL)
		disco(e, 60);
	else if ((key >= ONE && key <= SIX) || key == ENTER || key == ESC)
		another_key_hook(key, e);
	if (key == PAGE_UP || key == PAGE_DOWN)
		ft_debugnbr("IterationLevel", e->iter), e->hooking = 42;
	return (0);
}

int			mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == SCROLL_UP || button == LEFT_CLICK)
	{
		e->x += (WIN_SIZE / 2) - x;
		e->y += (WIN_SIZE / 2) - y;
		e->zoom /= 0.99;
	}
	else if (button == SCROLL_DOWN || button == RIGHT_CLICK)
		e->zoom *= 0.99;
	if (button == SCROLL_UP || button == SCROLL_DOWN || \
		button == LEFT_CLICK || button == RIGHT_CLICK)
		e->hooking = 1;
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
		e->hooking = 1;
	}
	return (0);
}

int			loop_hook(t_env *e)
{
	if (e->hooking)
	{
		ex_hook(e);
		e->hooking = 0;
	}
	return (0);
}
