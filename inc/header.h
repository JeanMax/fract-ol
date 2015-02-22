/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 13:23:15 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/22 12:31:28 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

/*
** define
*/
# define HEADER_H
# define WIN_SIZE 600
# define ESC 65307
# define ENTER 65293
# define NUM_PLUS 65451
# define NUM_MINUS 65453
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define PAGE_UP 65365
# define PAGE_DOWN 65366
# define SPACE 32
# define ONE 65457
# define TWO 65458
# define THREE 65459
# define FOUR 65460
# define FIVE 65461
# define SIX 65462
# define L_CTRL 65507
# define LEFT_CLICK 1
# define RIGHT_CLICK 3
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define USAGE 1
# define USAGE_MSG1 "Usage: ./fractol -[MJSCDN]"
# define USAGE_MSG2 "(Mandelbrot/Julia/Schottky/Chromosom/Douady-Rabbit/Noun)"
# define IMG_PTR 2
# define IMG_PTR_MSG "Error while creating img pointer."
# define PUT_PIX 3
# define PUT_PIX_MSG "Error while trying to put pixel out of image."
# define C_DOUBLE double complex

/*
** include
*/
# include "../libft/inc/libft.h"
# include <X11/X.h>
# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <complex.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

/*
** struct def
*/

typedef struct s_env	t_env;
struct	s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	int				bpp;
	int				x_len;
	int				endian;
	char			*data;
	t_char			fractal;
	t_char			iter;
	double			zoom;
	t_char			lock;
	double			x;
	double			y;
	int				color;
	C_DOUBLE		ju;
	t_char			hooking;
};

/*
** prototypes
*/
void	disco(t_env *e, int stop);
void	error(t_char c);
void	julia(t_env *e, t_char it);
void	noun(t_env *e, t_char it);
void	rabbit(t_env *e, t_char it);
void	chromosom(t_env *e, t_char it);
void	mandelbrot(t_env *e, t_char it);
void	schottky(t_env *e, t_char it);
int		key_hook(int key, t_env *e);
int		mouse_hook(int button, int x, int y, t_env *e);
int		mouse_move(int x, int y, t_env *e);
int		julia_move(int x, int y, t_env *e);
int		ex_hook(t_env *e);
int		loop_hook(t_env *e);
void	put_pixel_to_img(t_env *e, int x, int y, int color);

#endif
