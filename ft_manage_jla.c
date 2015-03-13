/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_jla.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 16:51:06 by vroche            #+#    #+#             */
/*   Updated: 2015/03/11 14:32:17 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** jla management fonctions
** key and mouse fonctions
*/

#include "fract_ol.h"

int		key_hook_jla(int keycode, t_env *env)
{
	t_mdb	*mdb;

	mdb = env->mdb;
	if (keycode == 258)
		mdb->mouse = (mdb->mouse == 0) ? 1 : 0;
	else if (keycode == 15)
		ft_init_jlastruct(mdb);
	else if (key_hook(keycode, mdb) == 0)
		return (0);
	if (keycode != 34)
		ft_julia(env, mdb);
	ft_expose_jla(env);
	return (0);
}

int		mouse_hook_jla(int mouse, int x, int y, t_env *env)
{
	t_mdb	*mdb;

	mdb = env->mdb;
	if (mouse == 4 && mdb->mouse == 0)
	{
		mdb->movex += ((WIDTH / 2) + mdb->movex - x) * 0.1;
		mdb->movey += ((HEIGHT / 2) + mdb->movey - y) * 0.1;
		mdb->zoom *= 1.1;
	}
	else if (mouse == 5 && mdb->mouse == 0 && (mdb->zoom / 1.1) > 0.3)
	{
		mdb->movex += ((WIDTH / 2) + mdb->movex - x) * (1 / 1.1 - 1);
		mdb->movey += ((HEIGHT / 2) + mdb->movey - y) * (1 / 1.1 - 1);
		mdb->zoom /= 1.1;
	}
	else
		return (0);
	ft_julia(env, mdb);
	ft_expose_jla(env);
	return (0);
}

int		mouse_motion_jla(int x, int y, t_env *env)
{
	t_mdb	*mdb;

	mdb = env->mdb;
	if (mdb->mouse == 0)
		return (0);
	mdb->pr = (((2 * (double)y) / (double)WIDTH) - 1.7);
	mdb->pi = ((double)x / (double)HEIGHT);
	ft_julia(env, mdb);
	ft_expose_jla(env);
	return (0);
}
