/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burningship.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 14:55:42 by vroche            #+#    #+#             */
/*   Updated: 2015/03/13 17:13:19 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Burningship (bns) fractal fonctions
** Init bns struct, expose and algorithm fonctions
*/

#include "fract_ol.h"

void		ft_init_bnsstruct(t_mdb *mdb)
{
	mdb->zoom = 0.6;
	mdb->movex = 75;
	mdb->movey = 60;
	mdb->maxiter = 30;
	mdb->oldre = 0;
	mdb->oldim = 0;
	mdb->info = 0;
	mdb->mouse = 1;
	mdb->coloroff = 0;
}

static void	ft_init_iter(t_mdb *mdb)
{
	mdb->pr = 1 * (mdb->x - mdb->movex - WIDTH / 2) / (0.5 * mdb->zoom * WIDTH);
	mdb->pi = (mdb->y - mdb->movey - HEIGHT / 2) / (0.5 * mdb->zoom * HEIGHT);
	mdb->i = 0;
	mdb->newre = 0;
	mdb->newim = 0;
}

int			ft_expose_bns(t_env *env)
{
	char	*str;

	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	if (env->mdb->info == 1)
	{
		mlx_put_image_to_window(env->mlx, env->win, env->img2, 0, 0);
		asprintf(&str, "zoom = %f", env->mdb->zoom);
		mlx_string_put(env->mlx, env->win, 3, 0, 0xFFFFFF, str);
		free(str);
		asprintf(&str, "maxiterations = %d", env->mdb->maxiter);
		mlx_string_put(env->mlx, env->win, 3, 15, 0xFFFFFF, str);
		free(str);
	}
	return (0);
}

void		ft_burningship(t_env *env, t_mdb *mdb)
{
	int color;

	mdb->x = 0;
	while (mdb->x < WIDTH)
	{
		mdb->y = 0;
		while (mdb->y < HEIGHT)
		{
			ft_init_iter(mdb);
			while (mdb->i < mdb->maxiter && \
				(mdb->newre * mdb->newre + mdb->newim * mdb->newim) < 4)
			{
				mdb->oldre = (mdb->newre < 0) ? -mdb->newre : mdb->newre;
				mdb->oldim = (mdb->newim < 0) ? -mdb->newim : mdb->newim;
				mdb->newre = SQUARE(mdb->oldre) - SQUARE(mdb->oldim) + mdb->pr;
				mdb->newim = 2 * mdb->oldre * mdb->oldim + mdb->pi;
				mdb->i++;
			}
			color = ft_hsvtorgb((mdb->i + mdb->coloroff) % 256, 255, \
								255 * (mdb->i < mdb->maxiter));
			ft_put_pixel_to_image(color, env, mdb->x, mdb->y);
			mdb->y++;
		}
		mdb->x++;
	}
}
