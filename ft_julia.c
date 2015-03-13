/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 17:47:47 by vroche            #+#    #+#             */
/*   Updated: 2015/03/13 17:12:48 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Julia (jla) fractal fonctions
** Init jla struct, expose and algorithm fonctions
*/

#include "fract_ol.h"

void		ft_init_jlastruct(t_mdb *mdb)
{
	mdb->zoom = 0.65;
	mdb->movex = 0;
	mdb->movey = 0;
	mdb->maxiter = 20;
	mdb->oldre = 0;
	mdb->oldim = 0;
	mdb->pr = -0.7;
	mdb->pi = 0.27015;
	mdb->info = 0;
	mdb->coloroff = 0;
	mdb->mouse = 0;
}

static void	ft_init_iter(t_mdb *mdb)
{
	mdb->newre = (mdb->x - WIDTH / 2 - mdb->movex) / (0.5 * mdb->zoom * WIDTH);
	mdb->newim = (mdb->y - HEIGHT / 2 - mdb->movey) \
				/ (0.5 * mdb->zoom * HEIGHT);
	mdb->i = 0;
}

int			ft_expose_jla(t_env *env)
{
	char	str[250];

	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	if (env->mdb->info == 1)
	{
		mlx_put_image_to_window(env->mlx, env->win, env->img2, 0, 0);
		sprintf(str, "zoom = %f", env->mdb->zoom);
		mlx_string_put(env->mlx, env->win, 3, 0, 0xFFFFFF, str);
		sprintf(str, "maxiterations = %d", env->mdb->maxiter);
		mlx_string_put(env->mlx, env->win, 3, 15, 0xFFFFFF, str);
		sprintf(str, "mouse = %d", env->mdb->mouse);
		mlx_string_put(env->mlx, env->win, 3, 30, 0xFFFFFF, str);
		sprintf(str, "real part = %f", env->mdb->pr);
		mlx_string_put(env->mlx, env->win, 3, 45, 0xFFFFFF, str);
		sprintf(str, "complex part = %f", env->mdb->pi);
		mlx_string_put(env->mlx, env->win, 3, 60, 0xFFFFFF, str);
	}
	return (0);
}

void		ft_julia(t_env *env, t_mdb *mdb)
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
				mdb->oldre = mdb->newre;
				mdb->oldim = mdb->newim;
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
