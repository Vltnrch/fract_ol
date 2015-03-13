/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 18:53:59 by vroche            #+#    #+#             */
/*   Updated: 2015/03/13 17:19:26 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Management fonction for fractol
** "Put pixel to image" fonction
** fonction to init environment struct
** fonction to print "usage: ..." / manage key / print key
*/

#include "fract_ol.h"

void	ft_put_pixel_to_image(unsigned long img_color, \
									t_env *env, int x, int y)
{
	unsigned char color1;
	unsigned char color2;
	unsigned char color3;
	unsigned char color4;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		color1 = (img_color & 0xFF000000) >> 24;
		color2 = (img_color & 0xFF0000) >> 16;
		color3 = (img_color & 0xFF00) >> 8;
		color4 = (img_color & 0xFF);
		env->data[y * env->sizeline + x * env->bpp / 8] = color4;
		env->data[y * env->sizeline + x * env->bpp / 8 + 1] = color3;
		env->data[y * env->sizeline + x * env->bpp / 8 + 2] = color2;
		env->data[y * env->sizeline + x * env->bpp / 8 + 3] = color1;
	}
}

void	init_conf(t_env *env, t_mdb *mdb)
{
	env->mlx = mlx_init();
	env->img = NULL;
	env->data = NULL;
	env->img2 = NULL;
	env->data2 = NULL;
	env->mdb = mdb;
}

void	ft_fract_usage(char *str)
{
	ft_putstr("usage : ");
	ft_putstr(str);
	ft_putstr(" mandelbrot / julia / burningship\n");
	exit(0);
}

int		key_hook(int keycode, t_mdb *mdb)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 126)
		mdb->movey -= 50 / mdb->zoom;
	else if (keycode == 125)
		mdb->movey += 50 / mdb->zoom;
	else if (keycode == 123)
		mdb->movex -= 50 / mdb->zoom;
	else if (keycode == 124)
		mdb->movex += 50 / mdb->zoom;
	else if (keycode == 78 && (mdb->zoom / 1.1) > 0.3)
		mdb->zoom /= 1.1;
	else if (keycode == 69)
		mdb->zoom *= 1.1;
	else if (keycode == 121 && (mdb->maxiter / 1.1) > 15)
		mdb->maxiter /= 1.1;
	else if (keycode == 116)
		mdb->maxiter *= 1.1;
	else if (keycode == 34)
		mdb->info = (mdb->info == 0) ? 1 : 0;
	else if (keycode >= 82 && keycode <= 92)
		mdb->coloroff = ceil(24 * (keycode - 82));
	else
		return (0);
	return (1);
}

void	ft_printkey_color(void)
{
	ft_putstr(".:| Key |:.\n\
...........\n\n\
Mouse wheel : Zoom -/+ on mouse position \
			(for Julia : mouse needs to be desactivated)\n\
Up/Down/Left/Right : Move\n\
-/+ : Zoom -/+\n\
Page Down/Page Up : maxiterations -/+\n\
Ctrl : Active or Desactivate mouse mouvement (only for Julia)\n\
i : Show informations\n\
0-9 : Color Keys\n\
r : Reset\n\
Esc : Exit!\n\
............\n\n");
}
