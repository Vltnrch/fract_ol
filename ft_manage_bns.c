/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_bns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroche <vroche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 14:57:36 by vroche            #+#    #+#             */
/*   Updated: 2015/03/11 14:30:50 by vroche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** bns management fonctions
** key and mouse fonctions
*/

#include "fract_ol.h"

int		key_hook_bns(int keycode, t_env *env)
{
	t_mdb	*mdb;

	mdb = env->mdb;
	if (keycode == 15)
		ft_init_bnsstruct(mdb);
	else if (key_hook(keycode, mdb) == 0)
		return (0);
	if (keycode != 34)
		ft_burningship(env, mdb);
	ft_expose_bns(env);
	return (0);
}

int		mouse_hook_bns(int mouse, int x, int y, t_env *env)
{
	t_mdb	*mdb;

	mdb = env->mdb;
	if (mouse == 4)
	{
		mdb->movex += ((WIDTH / 2) + mdb->movex - x) * 0.1;
		mdb->movey += ((HEIGHT / 2) + mdb->movey - y) * 0.1;
		mdb->zoom *= 1.1;
	}
	else if (mouse == 5 && (mdb->zoom / 1.1) > 0.3)
	{
		mdb->movex += ((WIDTH / 2) + mdb->movex - x) * (1 / 1.1 - 1);
		mdb->movey += ((HEIGHT / 2) + mdb->movey - y) * (1 / 1.1 - 1);
		mdb->zoom /= 1.1;
	}
	else
		return (0);
	ft_burningship(env, mdb);
	ft_expose_bns(env);
	return (0);
}
